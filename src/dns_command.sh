tool=${args[--tool]}
type=${args[--type]}
server=${args[--server]}

# default tool
checkAndSetIfEmpty tool "dig"

if [[ "$tool" == "dig" ]]; then
  if [[ ! $(command -v "$tool") ]]; then
    echo -e "$(red Missing "$tool")"
    exit 1
  fi

  # default type
  checkAndSetIfEmpty type "any"

  checkAndSetIfExisted server " @$server" server

  command="$tool$server $target -t $type"
fi
