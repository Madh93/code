#! /bin/bash

# Configuration
user="migue"
backupdir="/home/$user/.backups"
target="/"
backup="$backupdir/$(uname -n)_$(date +%s)_$(date +"%d-%m-%Y")"

while [ true ]; do

  # System backup at 03:00 (AM)
  if [ $(date "+%H") -eq 03 ]; then
    echo "Backup target: $target"
    echo "Backup destination: $backup.tar.gz"

    # Copy data
    start=`date +%s`
    echo "Copying files..."
    rsync -aAX --info=progress2 --exclude={"/dev/*","/proc/*","/sys/*","/tmp/*","/run/*","/mnt/*","/media/*","/lost+found","/home/*","/datos/*","/datos2/*"} $target $backup
    echo "Files copied!"

    # Compress data
    echo "Compressing files..."
    tar -zcvf $backup.tar.gz -C $backup .
    chown $user $backup.tar.gz
    echo "Files compressed!"

    # Delete temporal data
    echo "Removing temporal files..."
    rm -rf $backup
    echo "Temporal files removed!"

    # Delete oldest backup
    if [ $(find $backupdir/ | wc -l) -gt 8 ]; then
      echo "Removing old backup: $backupdir/$(find $backupdir/ -printf "%f\n" | sort | head -1)"
      rm $backupdir/$(find $backupdir/ -printf "%f\n" | sort | head -1)
      echo "Old backup removed!"
    fi

    # Time result
    end=`date +%s`
    runtime=$((end-start))
    ((sec=runtime%60, runtime/=60, min=runtime%60, hrs=runtime/60))
    timestamp=$(printf "%d:%02d:%02d" $hrs $min $sec)
    echo "System backup done in $timestamp"
  fi

  sleep 1h
done
