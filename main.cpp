#include <iostream>
#include <vector> 
#include <time.h> 
#include<string>  

using namespace std;


#include <tchar.h>
#include <Windows.h>

#include "EASendMailObj.tlh"
using namespace EASendMailObjLib;

const int ConnectNormal = 0;
const int ConnectSSLAuto = 1;
const int ConnectSTARTTLS = 2;
const int ConnectDirectSSL = 3;
const int ConnectTryTLS = 4;

int mailsend()
{
	::CoInitialize(NULL);

	IMailPtr oSmtp = NULL;
	oSmtp.CreateInstance(__uuidof(EASendMailObjLib::Mail));
	oSmtp->LicenseCode = _T("TryIt");

	// Set your sender email address
	oSmtp->FromAddr = _T("rahulkr.nssc@gmail.com");
	// Add recipient email address
	oSmtp->AddRecipientEx(_T("rahulkr3269@gmail.com"), 0);

	// Set email subject
	oSmtp->Subject = _T("simple email from Visual C++ project");
	// Set email body
	oSmtp->BodyText = _T("this is a test email sent from Visual C++ project, do not reply");

	// Your SMTP server address
	oSmtp->ServerAddr = _T("smtp.gmail.com");

	// User and password for ESMTP authentication, if your server doesn't
	// require User authentication, please remove the following codes.
	oSmtp->UserName = _T("rahulkr.nssc@gmail.com");
	oSmtp->Password = _T("password");

	// Most mordern SMTP servers require SSL/TLS connection now.
	// ConnectTryTLS means if server supports SSL/TLS, SSL/TLS will be used automatically.
	//oSmtp->ConnectType = ConnectTryTLS;

	// If your SMTP server uses 587 port
	//oSmtp->ServerPort = 587;

	// If your SMTP server requires SSL/TLS connection on 25/587/465 port
	 oSmtp->ServerPort = 25; // 25 or 587 or 465
	 oSmtp->ConnectType = ConnectSSLAuto;

	_tprintf(_T("Start to send email ...\r\n"));

	if (oSmtp->SendMail() == 0)
	{
		_tprintf(_T("email was sent successfully!\r\n"));
	}
	else
	{
		_tprintf(_T("failed to send email with the following error: %s\r\n"),
			(const TCHAR*)oSmtp->GetLastErrDescription());
	}

	return 0;
}


int main()
{
	mailsend();
	int n;

	

	cout << "Enter total number of Visitors" << endl;
	cin >> n;

	vector< vector< string > > data(n);

	string hname,hph,hemail;

	cout << "Enter Host Name  : ";
	cin >> hname;
	cout << "Enter Host Phone Number  : ";
	cin >> hph;
	cout << "Enter Host Email-id  : ";
	cin >> hemail;

	int checkin_count = 0, out_count = 0;

	int ch;

	

	for (int i = 0; ; i++) 
	{
		
		ch = 4;
		cout << "\n\n------------ Enter choice ---------------\n\n 1 for Check-In \n 2 for Check-Out \n\n------------------------------------------\n\n";
	
		cin >> ch;

		if (ch == 1 || ch == 2)
			cout<<"process \n\n";
		else	
		 cin >> ch;

		if (ch == 1)
		{
			 
			data[checkin_count].resize(7); 
			
			string str = to_string(checkin_count);
			data[checkin_count][0] = str;
			
			cout << "\n------------------------------- Enter Check-In Details ------------------------------------\n\n";
			
			cout << "Enter Guest Name  : ";
			cin >> data[checkin_count][1];
			cout << "Enter Guest Phone Number  : ";
			cin >> data[checkin_count][2];
			cout << "Enter Guest Email-id  : ";
			cin >> data[checkin_count][3];

			time_t my_time = time(NULL);

			data[checkin_count][4] = ctime(&my_time);
			checkin_count++;

		}

		if (ch == 2)
		{
			out_count++;


			string outname;
			cout << "\n------------------------------- Enter Check-Out Details ------------------------------------\n\n";

			cout << "Enter Guest Name  : ";
			cin >> outname;

			int index;

			int l = 0;
			int r = checkin_count - 1, res=0;
			while (l <= r)
			{
				int m = l + (r - l) / 2;

				int res;
				if (outname == (data[m][1]))
					res = 0;


				// Check if x is present at mid 
				if (res == 0)

				{
					index = m; break;
				}

				// If x greater, ignore left half 
				if (outname > (data[m][1]))
					l = m + 1;

				// If x is smaller, ignore right half 
				else
					r = m - 1;
			}

			time_t my_time = time(NULL);

			data[index][5] = ctime(&my_time);


			cout << "\n\n" << data[index][0] << "\n" << data[index][1] << "\n" << data[index][2] << "\n" << data[index][3] << "\n" << data[index][4] << "\n" << data[index][5] << "\n";


		}
		




	}

	return 0;

}
