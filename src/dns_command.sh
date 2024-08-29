tool=${args[--tool]}
type=${args[--type]}

# default tool
checkAndSetIfEmpty tool "dig"

if [[ "$tool" == "dig" ]]; then
  if [[ ! $(command -v "$tool") ]]; then
    echo -e "$(red Missing "$tool")"
    exit 1
  fi

  # default type
  checkAndSetIfEmpty type "any"

  command="$tool $target -t $type"
fi
