# Check and set if emtpy
checkAndSetIfEmpty() {
  local -n item=$1

  if [[ -z $item ]]; then
    item=$2
  fi
}

# Check and set if existed
checkAndSetIfExisted() {
  local -n item=$1
  local -n param_to_set=$3

  if [[ $item == 1 ]]; then
    if [[ -n $param_to_set ]]; then
      param_to_set=$2
    else
      item=$2
    fi
  fi
}

# Check and set if equal
checkAndSetIfEqual() {
  local -n item=$1
  local -n param_to_set=$4

  if [[ $item == "$2" ]]; then
    if [[ -z $param_to_set ]]; then
      item=$3
    else
      param_to_set=$3
    fi
  fi
}
