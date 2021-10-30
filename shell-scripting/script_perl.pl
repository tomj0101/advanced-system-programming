#!/usr/bin/perl
# comments in Perls
print "welcome to perl\n";

=begin comment
   multiline comments
   bla bla bla
=cut

# escaping charaters
print "Yes 
            \"Or\"
	        No\n";

# variable
$a = 10; # global varible
print "Value of a = $a \n";

# global read until find EOF
$var1 = << "EOF";
this is cool
this is cool too
this is no cool
EOF

print "$var1\n";


print <<EOF;
  yes also multi line
  very clean as well
  "let see"
  what can see
EOF


# data type
$age = 12;            # An integer assignment
$name = "Tom";        # A string 
$salary = 500.50;     # A floating point


# array 
@ages = (25, 30, 40);
@names = ("Tom", "Viny", "CHan");

# hash
%data = ('Crock', 45, 'Tim', 30, 'Tama', 40);
%data2 = ('John Paul' => 45, 'Lisa' => 30, 'Kumar' => 40);

@names = keys %data2;

print "$names[0]\n";
print "$names[1]\n";
print "$names[2]\n";


# v-string
$smile  = v9786;
print "smile = $smile\n";

# Special Literals
print "File name ". __FILE__ . "\n";
print "Line Number " . __LINE__ ."\n";
print "Package " . __PACKAGE__ ."\n";


# conditions
$status = (50 > 60 )? "A senior citizen" : "Not a senior citizen";

print "You are  - $status\n";


#date
$datestring = gmtime();
print "GMT date and time $datestring\n";
###
($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime();

printf("Time Format - HH:MM:SS\n");
printf("%02d:%02d:%02d\n", $hour, $min, $sec);

####
#
$epoc = time();

print "Number of seconds since Jan 1, 1970 - $epoc\n";


# Function
# Function definition
sub GetName {
   $var3 = 5; # private variable	
   print "Hi John!\n";
   # can have return 1; values....
}

# Function call
GetName();


# State variable
# There are another type of lexical variables, which are similar to private variables but they maintain their state and they do not get reinitialized upon multiple calls of the subroutines. These variables are defined using the state operator and available starting from Perl 5.9.4.

use feature 'state';

sub PrintCount {
   state $count = 0; # initial value

   print "Value of counter is $count\n";
   $count++;
}

for (1..5) {
   PrintCount();
}




# Perl Format

# Perl I/O
#open(DATA, "<file.txt") or die "Couldn't open file file.txt, $!";

#while(<DATA>) {
#   print "$_";
#}


# rename a file
# rename ("/usr/test/file1.txt", "/usr/test/file2.txt" );
#
# Deleting an Existing File
# unlink ("/usr/test/file1.txt");
#
# Create new Directory
#
# mkdir( $dir ) or die "Couldn't create $dir directory, $!";
#
#Remove a directory
#
#rmdir( $dir ) or die "Couldn't remove $dir directory, $!";
#
#Change a Directory


# Perl - Error Handling
# if(open(DATA, $file)) {
#   ...
#} else {
#   die "Error: Couldn't open the file - $!";
#}


# Perl regular expression
$bar = "This is foo and again foo";
if ($bar =~ /foo/) {
   print "First time is matching\n";
} else {
   print "First time is not matching\n";
}


$string = "The cat sat on the mat";
$string =~ s/cat/dog/;

print "$string\n";


# send email
$to = 'tom@gmail.com';
$from = 'webmaster@yourdomain.com';
$subject = 'Test Email';
$message = '<h1>This is test email sent by Perl Script</h1>';
 
open(MAIL, "|/usr/sbin/sendmail -t");
 
# Email Header
print MAIL "To: $to\n";
print MAIL "From: $from\n";
print MAIL "Subject: $subject\n\n";
print MAIL "Content-type: text/html\n";
# Email Body
print MAIL $message;

close(MAIL);
print "Email Sent Successfully\n";


# Perl GCI
=begin comment
#install apache and cgi module
sudo apt-get install apache2 libapache2-mod-wsgi
sudo a2enmod wsgi
sudo a2enmod cgi

sudo vim /etc/apache2/sites-enabled/000-default
---
Add the following lines after the DocumentRoot line:
         ScriptAlias /cgi-bin/ /var/cgi-bin/
         <Directory "/var/cgi-bin">
                 AllowOverride None
                 Options +ExecCGI -MultiViews +SymLinksIfOwnerMatch
                 Require all granted
         </Directory>

Now you should have:
<VirtualHost *:80>
        ServerAdmin webmaster@localhost
        DocumentRoot /var/www

         ScriptAlias /cgi-bin/ /var/cgi-bin/
         <Directory "/var/cgi-bin">
                 AllowOverride None
                 Options +ExecCGI -MultiViews +SymLinksIfOwnerMatch
                 Require all granted
         </Directory>

        ErrorLog ${APACHE_LOG_DIR}/error.log
        CustomLog ${APACHE_LOG_DIR}/access.log combined
</VirtualHost>


sudo systemctl restart apache2

cd /usr/lib/cgi-bin

sudo vim /usr/lib/cgi-bin/test.cgi

---
#!/usr/bin/perl
use strict;
use warnings;
 
print qq(Content-type: text/plain\n\n);
 
print "Hi from CGI using Perl\n";

--
sudo chmod 755 /var/cgi-bin/test.cgi


curl http://172.31.8.195/cgi-bin/test.cgi


=cut

