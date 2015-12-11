#! /bin/bash

get_pdf() {
  PDF=$BASE_URL`awk 'BEGIN{                                                                                      
    RS="</a>"
    IGNORECASE=1
    }
    {
      for(o=1;o<=NF;o++){
        if ( $o ~ /href/){
          gsub(/.*href=\042/,"",$o)
          gsub(/\042.*/,"",$o)
          print $(o)
        }
      }
    }' $FILE`
}

send_message() {

  $TELEGRAM -k $KEY -WR -e "msg Inmaculada $PDF"
}

TELEGRAM=/home/migue/educacion/tg/bin/telegram-cli
KEY=/home/migue/educacion/tg/bin/public-key.pub
URL=http://www.gobiernodecanarias.org/educacion/web/personal/docente/oferta/interinos_sustitutos/oferta_extraordinaria/maestros_sc/
BASE_URL=http://www.gobiernodecanarias.org
FILE=job.html
NEW_JOB=`curl -i -H "Accept: application/json" -H "Content-Type: application/json" -X GET $URL 2>&1 | grep class=\"documento\" | head -n 2 | tail -n 1 > $FILE`
OLD_PDF=
PDF=

get_pdf

while true; do

  OLD_PDF=$PDF
  NEW_JOB=`curl -i -H "Accept: application/json" -H "Content-Type: application/json" -X GET $URL 2>&1 | grep class=\"documento\" | head -n 2 | tail -n 1 > $FILE`
  
  get_pdf

  if [ $PDF != $OLD_PDF ]; then
    send_message
  fi

  sleep 15m
done
