#!/usr/bin/env bash
# This script was generated by bashly 1.1.9 (https://bashly.dannyb.co)
# Modifying it manually is not recommended

# :wrapper.bash3_bouncer
if [[ "${BASH_VERSINFO:-0}" -lt 4 ]]; then
  printf "bash version 4 or higher is required\n" >&2
  exit 1
fi

# :command.master_script

# :command.version_command
version_command() {
  echo "$version"
}

# :command.usage
h_usage() {
  if [[ -n $long_usage ]]; then
    printf "h - Hacker Tools\n"
    echo

  else
    printf "h - Hacker Tools\n"
    echo

  fi

  printf "%s\n" "$(bold "Usage:")"
  printf "  h COMMAND\n"
  printf "  h [COMMAND] --help | -h\n"
  printf "  h --version | -v\n"
  echo
  # :command.usage_commands
  printf "%s\n" "$(bold "Commands:")"
  printf "  %s   DNS related actions\n" "$(green "dns") "
  printf "  %s   Fuzz related actions\n" "$(green "fuzz")"
  echo

  # :command.long_usage
  if [[ -n $long_usage ]]; then
    printf "%s\n" "$(bold "Options:")"

    # :command.usage_fixed_flags
    printf "  %s\n" "$(magenta "--help, -h")"
    printf "    Show this help\n"
    echo
    printf "  %s\n" "$(magenta "--version, -v")"
    printf "    Show version number\n"
    echo

    # :command.usage_environment_variables
    printf "%s\n" "$(bold "Environment Variables:")"

    # :environment_variable.usage
    printf "  %s\n" "$(cyan "RHOST")"
    printf "\n"
    echo

    # :environment_variable.usage
    printf "  %s\n" "$(cyan "DNS_WORDLIST_SMALL")"
    printf "\n"
    printf "    Default: /opt/seclists/Discovery/Web-Content/raft-small-directories-lowercase.txt\n"
    echo

    # :environment_variable.usage
    printf "  %s\n" "$(cyan "DNS_WORDLIST_MEDIUM")"
    printf "\n"
    printf "    Default: /opt/seclists/Discovery/Web-Content/raft-medium-directories-lowercase.txt\n"
    echo

    # :environment_variable.usage
    printf "  %s\n" "$(cyan "DNS_WORDLIST_LARGE")"
    printf "\n"
    printf "    Default: /opt/seclists/Discovery/Web-Content/raft-large-directories-lowercase.txt\n"
    echo

    # :environment_variable.usage
    printf "  %s\n" "$(cyan "FILE_WORDLIST_SMALL")"
    printf "\n"
    printf "    Default: /opt/seclists/Discovery/Web-Content/raft-small-files-lowercase.txt\n"
    echo

    # :environment_variable.usage
    printf "  %s\n" "$(cyan "FILE_WORDLIST_MEDIUM")"
    printf "\n"
    printf "    Default: /opt/seclists/Discovery/Web-Content/raft-medium-files-lowercase.txt\n"
    echo

    # :environment_variable.usage
    printf "  %s\n" "$(cyan "FILE_WORDLIST_LARGE")"
    printf "\n"
    printf "    Default: /opt/seclists/Discovery/Web-Content/raft-large-files-lowercase.txt\n"
    echo

  fi
}

# :command.usage
h_dns_usage() {
  if [[ -n $long_usage ]]; then
    printf "h dns - DNS related actions\n"
    echo

  else
    printf "h dns - DNS related actions\n"
    echo

  fi

  printf "%s\n" "$(bold "Usage:")"
  printf "  h dns [TARGET] [OPTIONS]\n"
  printf "  h dns --help | -h\n"
  echo

  # :command.long_usage
  if [[ -n $long_usage ]]; then
    printf "%s\n" "$(bold "Options:")"

    # :command.usage_flags
    # :flag.usage
    printf "  %s\n" "$(magenta "--debug")"
    printf "    For debugging purpose\n"
    echo

    # :flag.usage
    printf "  %s\n" "$(magenta "--tool TOOL_ARG")"
    printf "    Tool for dns related actions (default: dig)\n"
    printf "    Allowed: dig\n"
    echo

    # :flag.usage
    printf "  %s\n" "$(magenta "--flag TOOL_ARG")"
    printf "    Extra flags that pass into the tool\n"
    echo

    # :flag.usage
    printf "  %s\n" "$(magenta "--type TYPE_ARG")"
    printf "    Type of server to discover (default: any)\n"
    printf "    Allowed: any, mx, txt, ns, cname, soa, aaaa\n"
    echo

    # :flag.usage
    printf "  %s\n" "$(magenta "--server SERVER_ARG")"
    printf "    Set the server ip\n"
    echo

    # :command.usage_fixed_flags
    printf "  %s\n" "$(magenta "--help, -h")"
    printf "    Show this help\n"
    echo

    # :command.usage_args
    printf "%s\n" "$(bold "Arguments:")"

    # :argument.usage
    printf "  %s\n" "$(blue "TARGET")"
    printf "    Target url\n"
    echo

    # :command.usage_examples
    printf "%s\n" "$(bold "Examples:")"
    printf "  h dns example.com --server 8.8.8.8\n"
    echo

  fi
}

# :command.usage
h_fuzz_usage() {
  if [[ -n $long_usage ]]; then
    printf "h fuzz - Fuzz related actions\n"
    echo

  else
    printf "h fuzz - Fuzz related actions\n"
    echo

  fi

  printf "%s\n" "$(bold "Usage:")"
  printf "  h fuzz [TARGET] [OPTIONS]\n"
  printf "  h fuzz --help | -h\n"
  echo

  # :command.long_usage
  if [[ -n $long_usage ]]; then
    printf "%s\n" "$(bold "Options:")"

    # :command.usage_flags
    # :flag.usage
    printf "  %s\n" "$(magenta "--debug")"
    printf "    For debugging purpose\n"
    echo

    # :flag.usage
    printf "  %s\n" "$(magenta "--tool TOOL_ARG")"
    printf "    Tool for fuzz related actions (default: ffuf)\n"
    printf "    Allowed: ffuf\n"
    echo

    # :flag.usage
    printf "  %s\n" "$(magenta "--type TYPE_ARG")"
    printf "    Type of thing to fuzz (default: dns)\n"
    printf "    Allowed: dns, dir, file\n"
    echo

    # :flag.usage
    printf "  %s\n" "$(magenta "--wordlist WORDLIST_ARG")"
    printf "    Wordlist to fuzz (default: seclist)\n"
    echo

    # :flag.usage
    printf "  %s\n" "$(magenta "--size SIZE_ARG")"
    printf "    The wordlist size\n"
    printf "    Allowed: small, medium, large\n"
    echo

    # :flag.usage
    printf "  %s\n" "$(magenta "--secure")"
    printf "    Set the protocol to use https\n"
    echo

    # :command.usage_fixed_flags
    printf "  %s\n" "$(magenta "--help, -h")"
    printf "    Show this help\n"
    echo

    # :command.usage_args
    printf "%s\n" "$(bold "Arguments:")"

    # :argument.usage
    printf "  %s\n" "$(blue "TARGET")"
    printf "    Target url\n"
    echo

    # :command.usage_examples
    printf "%s\n" "$(bold "Examples:")"
    printf "  h fuzz example.com --type dir --secure --size large\n"
    echo

  fi
}

# :command.normalize_input
normalize_input() {
  local arg flags

  while [[ $# -gt 0 ]]; do
    arg="$1"
    if [[ $arg =~ ^(--[a-zA-Z0-9_\-]+)=(.+)$ ]]; then
      input+=("${BASH_REMATCH[1]}")
      input+=("${BASH_REMATCH[2]}")
    elif [[ $arg =~ ^(-[a-zA-Z0-9])=(.+)$ ]]; then
      input+=("${BASH_REMATCH[1]}")
      input+=("${BASH_REMATCH[2]}")
    elif [[ $arg =~ ^-([a-zA-Z0-9][a-zA-Z0-9]+)$ ]]; then
      flags="${BASH_REMATCH[1]}"
      for ((i = 0; i < ${#flags}; i++)); do
        input+=("-${flags:i:1}")
      done
    else
      input+=("$arg")
    fi

    shift
  done
}

# :command.inspect_args
inspect_args() {
  if ((${#args[@]})); then
    readarray -t sorted_keys < <(printf '%s\n' "${!args[@]}" | sort)
    echo args:
    for k in "${sorted_keys[@]}"; do
      echo "- \${args[$k]} = ${args[$k]}"
    done
  else
    echo args: none
  fi

  if ((${#other_args[@]})); then
    echo
    echo other_args:
    echo "- \${other_args[*]} = ${other_args[*]}"
    for i in "${!other_args[@]}"; do
      echo "- \${other_args[$i]} = ${other_args[$i]}"
    done
  fi

  if ((${#deps[@]})); then
    readarray -t sorted_keys < <(printf '%s\n' "${!deps[@]}" | sort)
    echo
    echo deps:
    for k in "${sorted_keys[@]}"; do
      echo "- \${deps[$k]} = ${deps[$k]}"
    done
  fi

  if ((${#env_var_names[@]})); then
    readarray -t sorted_names < <(printf '%s\n' "${env_var_names[@]}" | sort)
    echo
    echo "environment variables:"
    for k in "${sorted_names[@]}"; do
      echo "- \$$k = ${!k:-}"
    done
  fi
}

# :command.user_lib
# src/lib/colors.sh
print_in_color() {
  local color="$1"
  shift
  if [[ -z ${NO_COLOR+x} ]]; then
    printf "$color%b\e[0m\n" "$*"
  else
    printf "%b\n" "$*"
  fi
}

red() { print_in_color "\e[31m" "$*"; }
green() { print_in_color "\e[32m" "$*"; }
yellow() { print_in_color "\e[33m" "$*"; }
blue() { print_in_color "\e[34m" "$*"; }
magenta() { print_in_color "\e[35m" "$*"; }
cyan() { print_in_color "\e[36m" "$*"; }
bold() { print_in_color "\e[1m" "$*"; }
underlined() { print_in_color "\e[4m" "$*"; }
red_bold() { print_in_color "\e[1;31m" "$*"; }
green_bold() { print_in_color "\e[1;32m" "$*"; }
yellow_bold() { print_in_color "\e[1;33m" "$*"; }
blue_bold() { print_in_color "\e[1;34m" "$*"; }
magenta_bold() { print_in_color "\e[1;35m" "$*"; }
cyan_bold() { print_in_color "\e[1;36m" "$*"; }
red_underlined() { print_in_color "\e[4;31m" "$*"; }
green_underlined() { print_in_color "\e[4;32m" "$*"; }
yellow_underlined() { print_in_color "\e[4;33m" "$*"; }
blue_underlined() { print_in_color "\e[4;34m" "$*"; }
magenta_underlined() { print_in_color "\e[4;35m" "$*"; }
cyan_underlined() { print_in_color "\e[4;36m" "$*"; }

# :command.command_functions
# :command.function
h_dns_command() {
  # src/dns_command.sh
  tool=${args[--tool]}
  flag=${args[--flag]}
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

    command="$tool$server $target -t $type $flag"
  fi

}

# :command.function
h_fuzz_command() {
  # src/fuzz_command.sh
  tool=${args[--tool]}
  flag=${args[--flag]}
  type=${args[--type]}

  # flags
  wordlist=${args[--wordlist]}
  secure=${args[--secure]}
  size=${args[--size]}

  # default tool
  checkAndSetIfEmpty tool "ffuf"

  if [[ "$tool" == "ffuf" ]]; then
    if [[ ! $(command -v "$tool") ]]; then
      echo -e "$(red Missing "$tool")"
      exit 1
    fi

    # default action
    checkAndSetIfEmpty type "dir"

    if [[ -n $wordlist ]]; then
      wordlist="-w $wordlist"
    else
      dnswordlist=$DNS_WORDLIST_MEDIUM
      checkAndSetIfEqual size "small" "$DNS_WORDLIST_SMALL" dnswordlist
      checkAndSetIfEqual size "medium" "$DNS_WORDLIST_MEDIUM" dnswordlist
      checkAndSetIfEqual size "large" "$DNS_WORDLIST_LARGE" dnswordlist

      filewordlist=$FILE_WORDLIST_MEDIUM
      checkAndSetIfEqual size "small" "$FILE_WORDLIST_SMALL" filewordlist
      checkAndSetIfEqual size "medium" "$FILE_WORDLIST_MEDIUM" filewordlist
      checkAndSetIfEqual size "large" "$FILE_WORDLIST_LARGE" filewordlist

      wordlist=x
      checkAndSetIfEqual type "dns" "-w \"$dnswordlist\"" wordlist

      checkAndSetIfEqual type "dir" "-w \"$dnswordlist\"" wordlist

      checkAndSetIfEqual type "file" "-w \"$filewordlist\"" wordlist
    fi

    # default http
    protocol=http
    checkAndSetIfExisted secure "https" protocol

    # default host
    params="-H \"Host: FUZZ.$target\""
    checkAndSetIfEqual type "dir" "" params
    checkAndSetIfEqual type "file" "" params

    # default just domain
    url="-u $protocol://$target"
    checkAndSetIfEqual type "dir" "-u $protocol://$target/FUZZ" url
    checkAndSetIfEqual type "file" "-u $protocol://$target/FUZZ" url

    # form the command
    command="$tool -c $url $wordlist $params $flag"
  fi

}

# :command.parse_requirements
parse_requirements() {
  # :command.fixed_flags_filter
  while [[ $# -gt 0 ]]; do
    case "${1:-}" in
      --version | -v)
        version_command
        exit
        ;;

      --help | -h)
        long_usage=yes
        h_usage
        exit
        ;;

      *)
        break
        ;;

    esac
  done

  # :command.environment_variables_filter
  # :command.environment_variables_default
  export DNS_WORDLIST_SMALL="${DNS_WORDLIST_SMALL:-/opt/seclists/Discovery/Web-Content/raft-small-directories-lowercase.txt}"
  export DNS_WORDLIST_MEDIUM="${DNS_WORDLIST_MEDIUM:-/opt/seclists/Discovery/Web-Content/raft-medium-directories-lowercase.txt}"
  export DNS_WORDLIST_LARGE="${DNS_WORDLIST_LARGE:-/opt/seclists/Discovery/Web-Content/raft-large-directories-lowercase.txt}"
  export FILE_WORDLIST_SMALL="${FILE_WORDLIST_SMALL:-/opt/seclists/Discovery/Web-Content/raft-small-files-lowercase.txt}"
  export FILE_WORDLIST_MEDIUM="${FILE_WORDLIST_MEDIUM:-/opt/seclists/Discovery/Web-Content/raft-medium-files-lowercase.txt}"
  export FILE_WORDLIST_LARGE="${FILE_WORDLIST_LARGE:-/opt/seclists/Discovery/Web-Content/raft-large-files-lowercase.txt}"

  env_var_names+=("RHOST")
  env_var_names+=("DNS_WORDLIST_SMALL")
  env_var_names+=("DNS_WORDLIST_MEDIUM")
  env_var_names+=("DNS_WORDLIST_LARGE")
  env_var_names+=("FILE_WORDLIST_SMALL")
  env_var_names+=("FILE_WORDLIST_MEDIUM")
  env_var_names+=("FILE_WORDLIST_LARGE")

  # :command.command_filter
  action=${1:-}

  case $action in
    -*) ;;

    dns)
      action="dns"
      shift
      h_dns_parse_requirements "$@"
      shift $#
      ;;

    fuzz)
      action="fuzz"
      shift
      h_fuzz_parse_requirements "$@"
      shift $#
      ;;

    # :command.command_fallback
    "")
      h_usage >&2
      exit 1
      ;;

    *)
      printf "invalid command: %s\n" "$action" >&2
      exit 1
      ;;

  esac

  # :command.parse_requirements_while
  while [[ $# -gt 0 ]]; do
    key="$1"
    case "$key" in

      -?*)
        printf "invalid option: %s\n" "$key" >&2
        exit 1
        ;;

      *)
        # :command.parse_requirements_case
        # :command.parse_requirements_case_simple
        printf "invalid argument: %s\n" "$key" >&2
        exit 1

        ;;

    esac
  done

}

# :command.parse_requirements
h_dns_parse_requirements() {
  # :command.fixed_flags_filter
  while [[ $# -gt 0 ]]; do
    case "${1:-}" in
      --help | -h)
        long_usage=yes
        h_dns_usage
        exit
        ;;

      *)
        break
        ;;

    esac
  done

  # :command.command_filter
  action="dns"

  # :command.parse_requirements_while
  while [[ $# -gt 0 ]]; do
    key="$1"
    case "$key" in
      # :flag.case
      --debug)

        # :flag.case_no_arg
        args['--debug']=1
        shift
        ;;

      # :flag.case
      --tool)

        # :flag.case_arg
        if [[ -n ${2+x} ]]; then
          args['--tool']="$2"
          shift
          shift
        else
          printf "%s\n" "--tool requires an argument: --tool TOOL_ARG" >&2
          exit 1
        fi
        ;;

      # :flag.case
      --flag)

        # :flag.case_arg
        if [[ -n ${2+x} ]]; then
          args['--flag']="$2"
          shift
          shift
        else
          printf "%s\n" "--flag requires an argument: --flag TOOL_ARG" >&2
          exit 1
        fi
        ;;

      # :flag.case
      --type)

        # :flag.case_arg
        if [[ -n ${2+x} ]]; then
          args['--type']="$2"
          shift
          shift
        else
          printf "%s\n" "--type requires an argument: --type TYPE_ARG" >&2
          exit 1
        fi
        ;;

      # :flag.case
      --server)

        # :flag.case_arg
        if [[ -n ${2+x} ]]; then
          args['--server']="$2"
          shift
          shift
        else
          printf "%s\n" "--server requires an argument: --server SERVER_ARG" >&2
          exit 1
        fi
        ;;

      -?*)
        printf "invalid option: %s\n" "$key" >&2
        exit 1
        ;;

      *)
        # :command.parse_requirements_case
        # :command.parse_requirements_case_simple
        # :argument.case
        if [[ -z ${args['target']+x} ]]; then
          args['target']=$1
          shift
        else
          printf "invalid argument: %s\n" "$key" >&2
          exit 1
        fi

        ;;

    esac
  done

  # :command.whitelist_filter
  if [[ ${args['--tool']:-} ]] && [[ ! ${args['--tool']:-} =~ ^(dig)$ ]]; then
    printf "%s\n" "--tool must be one of: dig" >&2
    exit 1
  fi
  if [[ ${args['--type']:-} ]] && [[ ! ${args['--type']:-} =~ ^(any|mx|txt|ns|cname|soa|aaaa)$ ]]; then
    printf "%s\n" "--type must be one of: any, mx, txt, ns, cname, soa, aaaa" >&2
    exit 1
  fi

}

# :command.parse_requirements
h_fuzz_parse_requirements() {
  # :command.fixed_flags_filter
  while [[ $# -gt 0 ]]; do
    case "${1:-}" in
      --help | -h)
        long_usage=yes
        h_fuzz_usage
        exit
        ;;

      *)
        break
        ;;

    esac
  done

  # :command.command_filter
  action="fuzz"

  # :command.parse_requirements_while
  while [[ $# -gt 0 ]]; do
    key="$1"
    case "$key" in
      # :flag.case
      --debug)

        # :flag.case_no_arg
        args['--debug']=1
        shift
        ;;

      # :flag.case
      --tool)

        # :flag.case_arg
        if [[ -n ${2+x} ]]; then
          args['--tool']="$2"
          shift
          shift
        else
          printf "%s\n" "--tool requires an argument: --tool TOOL_ARG" >&2
          exit 1
        fi
        ;;

      # :flag.case
      --type)

        # :flag.case_arg
        if [[ -n ${2+x} ]]; then
          args['--type']="$2"
          shift
          shift
        else
          printf "%s\n" "--type requires an argument: --type TYPE_ARG" >&2
          exit 1
        fi
        ;;

      # :flag.case
      --wordlist)

        # :flag.case_arg
        if [[ -n ${2+x} ]]; then
          args['--wordlist']="$2"
          shift
          shift
        else
          printf "%s\n" "--wordlist requires an argument: --wordlist WORDLIST_ARG" >&2
          exit 1
        fi
        ;;

      # :flag.case
      --size)

        # :flag.case_arg
        if [[ -n ${2+x} ]]; then
          args['--size']="$2"
          shift
          shift
        else
          printf "%s\n" "--size requires an argument: --size SIZE_ARG" >&2
          exit 1
        fi
        ;;

      # :flag.case
      --secure)

        # :flag.case_no_arg
        args['--secure']=1
        shift
        ;;

      -?*)
        printf "invalid option: %s\n" "$key" >&2
        exit 1
        ;;

      *)
        # :command.parse_requirements_case
        # :command.parse_requirements_case_simple
        # :argument.case
        if [[ -z ${args['target']+x} ]]; then
          args['target']=$1
          shift
        else
          printf "invalid argument: %s\n" "$key" >&2
          exit 1
        fi

        ;;

    esac
  done

  # :command.whitelist_filter
  if [[ ${args['--tool']:-} ]] && [[ ! ${args['--tool']:-} =~ ^(ffuf)$ ]]; then
    printf "%s\n" "--tool must be one of: ffuf" >&2
    exit 1
  fi
  if [[ ${args['--type']:-} ]] && [[ ! ${args['--type']:-} =~ ^(dns|dir|file)$ ]]; then
    printf "%s\n" "--type must be one of: dns, dir, file" >&2
    exit 1
  fi
  if [[ ${args['--size']:-} ]] && [[ ! ${args['--size']:-} =~ ^(small|medium|large)$ ]]; then
    printf "%s\n" "--size must be one of: small, medium, large" >&2
    exit 1
  fi

}

# :command.user_hooks
before_hook() {
  # src/before.sh
  # echo "==[ Before Hook Called ]=="
  # inspect_args

  target=${args[target]}

  if [[ -z $target ]]; then
    if [[ -z $RHOST ]]; then
      echo -e "$(red Invalid target/RHOST)"
      exit 1
    fi

    target=$RHOST
  fi

}

after_hook() {
  # src/after.sh
  debug=${args[--debug]}

  # print
  echo -e "$(green Running command:)" "$(yellow "$command")"

  # execute
  if [[ -z $DEBUG ]] && [[ -z $debug ]]; then
    eval "$command"
  fi

}

# :command.initialize
initialize() {
  version="0.1.0"
  long_usage=''
  set -e

  # :command.environment_variables_default
  export DNS_WORDLIST_SMALL="${DNS_WORDLIST_SMALL:-/opt/seclists/Discovery/Web-Content/raft-small-directories-lowercase.txt}"
  export DNS_WORDLIST_MEDIUM="${DNS_WORDLIST_MEDIUM:-/opt/seclists/Discovery/Web-Content/raft-medium-directories-lowercase.txt}"
  export DNS_WORDLIST_LARGE="${DNS_WORDLIST_LARGE:-/opt/seclists/Discovery/Web-Content/raft-large-directories-lowercase.txt}"
  export FILE_WORDLIST_SMALL="${FILE_WORDLIST_SMALL:-/opt/seclists/Discovery/Web-Content/raft-small-files-lowercase.txt}"
  export FILE_WORDLIST_MEDIUM="${FILE_WORDLIST_MEDIUM:-/opt/seclists/Discovery/Web-Content/raft-medium-files-lowercase.txt}"
  export FILE_WORDLIST_LARGE="${FILE_WORDLIST_LARGE:-/opt/seclists/Discovery/Web-Content/raft-large-files-lowercase.txt}"

  # src/initialize.sh
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

    if [[ -n $item ]]; then
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

}

# :command.run
run() {
  declare -A args=()
  declare -A deps=()
  declare -a other_args=()
  declare -a env_var_names=()
  declare -a input=()
  normalize_input "$@"
  parse_requirements "${input[@]}"
  before_hook

  case "$action" in
    "dns") h_dns_command ;;
    "fuzz") h_fuzz_command ;;
  esac

  after_hook
}

initialize
run "$@"
