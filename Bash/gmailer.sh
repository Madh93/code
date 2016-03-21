#! /bin/bash

# NAME          : gmailer.sh
# DESCRIPTION   : Check and notify new gmails
# AUTHOR        : Madh93 (Miguel Hernandez)
# VERSION       : 0.0.1
# LICENSE       : GNU General Public License v3
# USAGE         : bash gmailer.sh


# CONFIG
GMAIL_RUBY_SCRIPT="$HOME/Aplicaciones/gmailer.rb"
GMAIL_USER=""
GMAIL_PASS=""
GMAIL_ICON="$HOME/Imágenes/Iconos/gmail.png"
GMAIL_SOUND="/usr/share/sounds/freedesktop/stereo/complete.oga"
GMAIL_INTERVAL="1m"


# Run
while true; do

  xml=$(curl -u $GMAIL_USER:$GMAIL_PASS --silent 'https://mail.google.com/mail/feed/atom')
  count=$(echo $xml | grep "<fullcount>0</fullcount>")

  if [[ $count == "" ]]; then
    # Sound notification
    paplay $GMAIL_SOUND

    # Desktop notifications
    count=$(ruby $GMAIL_RUBY_SCRIPT "$xml" --count)

    for (( i=0; i<$count; i++ )); do
      mail=$(ruby $GMAIL_RUBY_SCRIPT "$xml" --read $i)
      name=$(echo $mail | cut -d ';' -f1)
      title=$(echo $mail | cut -d ';' -f2)

      notify-send --icon=$GMAIL_ICON --expire-time=5000 "$name" "$title"
    done
  fi

  sleep $GMAIL_INTERVAL

done