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

  printf "%s\n" "Usage:"
  printf "  h COMMAND\n"
  printf "  h [COMMAND] --help | -h\n"
  printf "  h --version | -v\n"
  echo
  # :command.usage_commands
  printf "%s\n" "Commands:"
  printf "  %s   DNS related actions\n" "dns "
  printf "  %s   Fuzz related actions\n" "fuzz"
  echo

  # :command.long_usage
  if [[ -n $long_usage ]]; then
    printf "%s\n" "Options:"

    # :command.usage_fixed_flags
    printf "  %s\n" "--help, -h"
    printf "    Show this help\n"
    echo
    printf "  %s\n" "--version, -v"
    printf "    Show version number\n"
    echo

    # :command.usage_environment_variables
    printf "%s\n" "Environment Variables:"

    # :environment_variable.usage
    printf "  %s\n" "RHOST"
    printf "\n"
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

  printf "%s\n" "Usage:"
  printf "  h dns [TARGET] [OPTIONS]\n"
  printf "  h dns --help | -h\n"
  echo

  # :command.long_usage
  if [[ -n $long_usage ]]; then
    printf "%s\n" "Options:"

    # :command.usage_flags
    # :flag.usage
    printf "  %s\n" "--tool TOOL_ARG"
    printf "    Tool for dns related actions (default: dig)\n"
    echo

    # :flag.usage
    printf "  %s\n" "--type, -t TYPE_ARG"
    printf "    Type of server to discover (default: any)\n"
    echo

    # :command.usage_fixed_flags
    printf "  %s\n" "--help, -h"
    printf "    Show this help\n"
    echo

    # :command.usage_args
    printf "%s\n" "Arguments:"

    # :argument.usage
    printf "  %s\n" "TARGET"
    printf "    Target url\n"
    echo

    # :command.usage_examples
    printf "%s\n" "Examples:"
    printf "  t dns example.com\n"
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

  printf "%s\n" "Usage:"
  printf "  h fuzz [TARGET] [OPTIONS]\n"
  printf "  h fuzz --help | -h\n"
  echo

  # :command.long_usage
  if [[ -n $long_usage ]]; then
    printf "%s\n" "Options:"

    # :command.usage_flags
    # :flag.usage
    printf "  %s\n" "--tool TOOL_ARG"
    printf "    Tool for fuzz related actions (default: ffuf)\n"
    echo

    # :flag.usage
    printf "  %s\n" "--type, -t TYPE_ARG"
    printf "    Type of thing to fuzz (default: dns)\n"
    echo

    # :flag.usage
    printf "  %s\n" "--wordlist, -w WORDLIST_ARG"
    printf "    Wordlist to fuzz (default:\n    dns:/opt/fuzzdb/discovery/dns/dnsmapCommonSubdomains.txt dir:)\n"
    echo

    # :flag.usage
    printf "  %s\n" "--secure"
    printf "    Set the protocol to use https\n"
    echo

    # :command.usage_fixed_flags
    printf "  %s\n" "--help, -h"
    printf "    Show this help\n"
    echo

    # :command.usage_args
    printf "%s\n" "Arguments:"

    # :argument.usage
    printf "  %s\n" "TARGET"
    printf "    Target url\n"
    echo

    # :command.usage_examples
    printf "%s\n" "Examples:"
    printf "  t fuzz example.com\n"
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
  target=${args[target]}
  tool=${args[--tool]}
  type=${args[--type]}

  if [[ -z $tool ]]; then
    tool=dig
  fi

  if [[ -z $type ]]; then
    type=any
  fi

  command="$tool $target -t $type"

  # print
  echo -e "$(green Command:)" "$(yellow "$command")"

  # execute
  if [[ -z $DEBUG ]]; then
    eval $command
  fi

}

# :command.function
h_fuzz_command() {
  # src/fuzz_command.sh
  target=${args[target]}
  tool=${args[--tool]}
  type=${args[--type]}
  wordlist=${args[--wordlist]}
  secure=${args[--secure]}
  params=
  url=
  protocol=http

  if [[ -z $target ]]; then
    if [[ -z $RHOST ]]; then
      echo -e "Invalid target/RHOST"
      exit 1
    fi

    target=$RHOST
  fi

  if [[ -z $tool ]]; then
    tool=ffuf
  fi

  if [[ -z $type ]]; then
    type=dns
  fi

  if [[ -z $wordlist ]]; then
    if [[ "$type" == "dns" ]]; then
      wordlist="-w \"/opt/fuzzdb/discovery/dns/dnsmapCommonSubdomains.txt\""
    fi

    if [[ "$type" == "dir" ]]; then
      wordlist="-w \"/opt/fuzzdb/discovery/predictable-filepaths/filename-dirname-bruteforce/raft-small-directories-lowercase.txt\""
    fi
  fi

  if [[ -n "$secure" ]]; then
    protocol=https
  fi

  if [[ "$type" == "dns" ]]; then
    params="-H \"Host: FUZZ.$target\""
    url="-u $protocol://$target"
  fi

  if [[ "$type" == "dir" ]]; then
    url="-u $protocol://$target/FUZZ"
  fi

  command="$tool -c $url $wordlist $params"

  # print
  echo -e "$(green Command:)" "$(yellow "$command")"

  # execute
  if [[ -z $DEBUG ]]; then
    eval $command
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

  env_var_names+=("RHOST")

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
      --type | -t)

        # :flag.case_arg
        if [[ -n ${2+x} ]]; then
          args['--type']="$2"
          shift
          shift
        else
          printf "%s\n" "--type requires an argument: --type, -t TYPE_ARG" >&2
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
      --type | -t)

        # :flag.case_arg
        if [[ -n ${2+x} ]]; then
          args['--type']="$2"
          shift
          shift
        else
          printf "%s\n" "--type requires an argument: --type, -t TYPE_ARG" >&2
          exit 1
        fi
        ;;

      # :flag.case
      --wordlist | -w)

        # :flag.case_arg
        if [[ -n ${2+x} ]]; then
          args['--wordlist']="$2"
          shift
          shift
        else
          printf "%s\n" "--wordlist requires an argument: --wordlist, -w WORDLIST_ARG" >&2
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

}

# :command.initialize
initialize() {
  version="0.1.0"
  long_usage=''
  set -e

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

  case "$action" in
    "dns") h_dns_command ;;
    "fuzz") h_fuzz_command ;;
  esac
}

initialize
run "$@"
