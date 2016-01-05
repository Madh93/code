Name:           oranchelo-icon-theme
Version:        0.7.0
Release:        1%{?dist}
Summary:        Oranchelo is a flat-design icon theme for XFCE4 
License:        GPLv3  
URL:            http://zayronxio.deviantart.com/art/Oranchelo-icons-beta-v0-7-567346368
Source0:        https://github.com/Madh93/oranchelo-icon-theme/archive/v0.7.0.tar.gz   
BuildRoot:      %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n) 
BuildArch:      noarch

#BuildRequires:  
#Requires:       

%description 
Oranchelo is a flat-design icon theme for XFCE4 based on Super Flat Remix and inspired by "Corny icons" by Patryk Goworowski.

%prep
%setup -q

%build
#%%configure
#make %{?_smp_mflags}

%install
rm -rf $RPM_BUILD_ROOT
install -m 755 -d $RPM_BUILD_ROOT/usr/share/icons/
cp -r Oranchelo $RPM_BUILD_ROOT/usr/share/icons/  
cp -r Oranchelo-Green  $RPM_BUILD_ROOT/usr/share/icons/

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root,-)
/usr/share/icons/Oranchelo*
%doc

%changelog
