# Security
### Linux password manager.
pass - the standard unix password manager https://www.passwordstore.org/, a well know solution is https://www.lastpass.com/ 
```
sudo apt install pass

- gpg - OpenPGP encryption and signing tool
gpg --full-generate-key

gpg (GnuPG) 2.2.20; Copyright (C) 2020 Free Software Foundation, Inc.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

gpg: directory '/home/tom/.gnupg' created
gpg: keybox '/home/tom/.gnupg/pubring.kbx' created
Please select what kind of key you want:
   (1) RSA and RSA (default)
   (2) DSA and Elgamal
   (3) DSA (sign only)
   (4) RSA (sign only)
  (14) Existing key from card
Your selection? 
RSA keys may be between 1024 and 4096 bits long.
What keysize do you want? (3072) 
Requested keysize is 3072 bits
Please specify how long the key should be valid.
         0 = key does not expire
      <n>  = key expires in n days
      <n>w = key expires in n weeks
      <n>m = key expires in n months
      <n>y = key expires in n years
Key is valid for? (0) 
Key does not expire at all
Is this correct? (y/N) y

GnuPG needs to construct a user ID to identify your key.

Real name: tom@vm1
Email address: tom@vm1

Comment: 
You selected this USER-ID:
    "tomas@vm-ubuntu-dev1 <tomas@vm-ubuntu-dev1>"
    
Change (N)ame, (C)omment, (E)mail or (O)kay/(Q)uit? o


tom@vm:~$ gpg --list-secret-keys --keyid-format LONG
gpg: checking the trustdb
gpg: marginals needed: 3  completes needed: 1  trust model: pgp
gpg: depth: 0  valid:   1  signed:   0  trust: 0-, 0q, 0n, 0m, 0f, 1u
/home/tom/.gnupg/pubring.kbx
------------------------------
sec   rsa3072/123456....KEY 2022-04-10 [SC]

- Initialize pass env
tom@vm:~$ pass init "123456....KEY"
Password store initialized for 123456....KEY

- Insert new password
tom@vm1:~$ pass insert personal/facebook.com
Enter password for personal/facebook.com: 
Retype password for personal/facebook.com: 

- List my passwords
tom@vm:~$ pass
Password Store
└── Personal
    └── facebook.com
    
tom@vm:~$ cd ~/.password-store/
tom@vm:~/.password-store$ ls personal/
facebook.com.gpg

- Get my website password
tom@vm:~$ gpg -d ~/.password-store/personal/facebook.com.gpg 
gpg: encrypted with 3072-bit RSA key, ID FB6F8DB64C9AA833, created 2022-04-10
      "tom@vm1 <tom@vm1>"
abc123

Compatible Clients:
- Android-Password-Store: Android app
- passforios: iOS app
- passff: Firefox plugin
- browserpass: Chrome plugin
- Pass4Win: Windows client
```


### ClamAV.
ClamAV® is an open-source antivirus engine for detecting trojans, viruses, malware & other malicious threats.
```
$ sudo apt install clamav
$ sudo freshclam
$ clamscan --help

$ time clamscan -r -i --bell ~/Downloads/

----------- SCAN SUMMARY -----------
Known viruses: 8653189
Engine version: 0.103.6
Scanned directories: 821
Scanned files: 4750
Infected files: 0
Data scanned: 183.81 MB
Data read: 64.74 MB (ratio 2.84:1)
Time: 79.738 sec (1 m 19 s)
Start Date: 2023:02:19 18:30:16
End Date:   2023:02:19 18:31:36

real	1m19.752s
user	1m16.226s
sys	0m2.700s


$ clamscan -r --remove # Don't use --remove because can remove good windows .exe

- Install Desktop app for manage ClamAV
$ sudo apt update
$ sudo apt install clamtk

```