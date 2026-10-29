#!/usr/bin/env bash
#
# Rename the template's project, namespace, include directory, and targets.
#
#   ./scripts/rename.sh my_sketch
#
# Replaces cpp_starter/cpp-starter, starter (namespace, starter:: aliases,
# starter_* targets, include/starter/) and STARTER_ (guards, options) with
# the new name, then deletes this script. Run it once, from a clean tree.
#

set -euo pipefail

if [[ $# -ne 1 || ! $1 =~ ^[a-z][a-z0-9_]*$ ]]; then
    echo "usage: $0 <name>   (lower_snake_case, e.g. my_sketch)" >&2
    exit 1
fi

name=$1
upper=$(tr '[:lower:]' '[:upper:]' <<<"$name")
dashed=${name//_/-}

cd "$(git rev-parse --show-toplevel)"

if [[ -n $(git status --porcelain) ]]; then
    echo "error: commit or stash your changes first" >&2
    exit 1
fi

git ls-files -z -- ':!LICENSE' ':!scripts/rename.sh' |
    xargs -0 perl -pi -e "
        s/cpp-starter/${dashed}/g;
        s/cpp_starter/${name}/g;
        s/STARTER_/${upper}_/g;
        s/\\bstarter/${name}/g;
    "

for dir in components/*/include/starter; do
    git mv "$dir" "$(dirname "$dir")/${name}"
done

git rm -q scripts/rename.sh
rm -rf build

echo "Renamed to '${name}'. Review with 'git diff --stat', then reconfigure:"
echo "    cmake --preset debug && cmake --build --preset debug"
