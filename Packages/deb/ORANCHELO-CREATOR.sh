#!/bin/sh

# Configure your paths and filenames
SOURCE_BIN_PATH=bin
SOURCE_BIN=Oranchelo*
DEB_FOLDER=oranchelo-icon-theme
DEB_VERSION=0.7.0~ubuntu15.10.1
# DIST_VERSION=ubuntu15.04.1

DEB_FOLDERNAME=$DEB_FOLDER-$DEB_VERSION

# Create your scripts source dir
mkdir $DEB_FOLDERNAME

# Copy your script to the source dir
cp -r $SOURCE_BIN_PATH/$SOURCE_BIN $DEB_FOLDERNAME 
cd $DEB_FOLDERNAME

# Create the packaging skeleton (debian/*)
dh_make -s --indep --createorig 

# Remove make calls
grep -v makefile debian/rules > debian/rules.new 
mv debian/rules.new debian/rules 

# debian/install must contain the list of scripts to install 
# as well as the target directory
echo $SOURCE_BIN usr/share/icons > debian/install 

# Post isntallation
cp ../config/postinst debian/postinst

# Package details
cp ../config/control debian/control

# Changelog
cp ../config/changelog debian/changelog

# Copyright
cp ../config/copyright debian/copyright

# Remove the example files
rm debian/*.ex
rm debian/*.EX
rm debian/README.*

# Build the package.
# You  will get a lot of warnings and ../somescripts_0.1-1_all.deb
debuild

# To build package with GPG Key for LaunchPad/PPA (Comentar para construir .deb)
# debuild -k'CLAVESECRETA' -S

# To Launchpad (No ejecutar en el script, sino por separado)
###### dput ppa:oranchelo/oranchelo-icon-theme oranchelo-icon-theme_0.6.8~ubuntu14.04.1_source.changes