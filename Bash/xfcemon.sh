#! /bin/bash

# NAME          : xfcemon.sh
# DESCRIPTION   : Launch XFCE/Cinnamon apps
# AUTHOR        : Madh93 (Miguel Hernandez)
# VERSION       : 0.0.1
# LICENSE       : GNU General Public License v3
# USAGE         : bash xfcemon.sh


# CONFIG
cinnamon=$(ps -A | grep cinnamon)


# feature() {
#   if [[ $cinnamon != "" ]] ; then
#     CINNAMON COMMAND
#   else
#     XFCE COMMAND
#   fi
# }

power_off() {
  if [[ $cinnamon != "" ]] ; then
    cinnamon-session-quit --power-off
  else
    xfce4-session-logout
  fi
}

settings() {
  if [[ $cinnamon != "" ]] ; then
    cinnamon-settings
  else
    xfce4-settings-manager
  fi
}

show_help() {

  echo -e "\nxfcemon: launch XFCE/Cinnamon apps.\n"
  echo -e "Usage: xfcemon [options]\n"
  echo -e "Options:"
  echo "  -p, --power-off   Show power off window"
  echo "  -s, --settings    Show settings window"
  echo "  -h, --help        Print help"
}


# MAIN
case "$1" in 
  -p | --power-off)
    power_off
    ;;
  -s | --settings)
    settings
    ;;
  -h | --help)
    show_help
    ;;
  *)
    echo -e "$xfcemon: unknown argument.\nRun 'xfcemon -h' for usage."
    ;;
esac