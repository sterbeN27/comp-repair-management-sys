#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// CODED BY:	|	STEVEN	|	github.com/sterbeN27
struct visit
{
	int id;
	char name[20];
	int num;
	char sex;
	const char* serv;
	int dd_st, mm_st, yy_st, dd_ed, mm_ed, yy_ed, fee, days;
	const char* type;
	const char* paym;
	float balnc, paid;
};

void admin_log();
void admin_menu();
void admin_add();
void admin_chg();
void engnr_log();
void engnr_menu();
void engnr_srv();
void cus_prof(struct visit* v);
void cus_serv(struct visit* v);
void cus_pay(struct visit* v);
void visit_id(struct visit* v);
void pay_update(struct visit* v);
void srv_update(struct visit* v);
void chng_srv();
void chng_pay();
void srch();
void sleep(unsigned ms);
int realtime();
int srvdate(struct visit* v);
int write(struct visit* v);
int date_special(struct visit* v);


/*======================================================================*/
/*					            MAIN PAGE								*/
/*======================================================================*/
int main()
{
	int log_op;

	system("cls");
	realtime();
	printf("\n\t\t===========================================");
	printf("\n\t\tWelcome to Malaysia Computer/Laptop Repair!");
	printf("\n\t\t===========================================");
	printf("\n\n\t\tLogin as: ");
	printf("\n\n\t\t1. Admin \n\t\t2. Engineer\n\t\t3. Exit\n");
	printf("\n\t\t\t__________________\n");
	printf("\t\t\tEnter your option: ");
	scanf("%d", &log_op);
	switch (log_op)
	{
	case 1:
		admin_log();
		break;
	case 2:
		engnr_log();
		break;
	case 3:
		exit(0);
	default:
		printf("\n\tError! \n\tInvalid Input!\n");
		sleep(1000);
		printf("\tPlease Restart the program!");
		sleep(2000);
		exit(0);
	}
	return 0;
}

/*======================================================================*/
/*					             ADMIN				    				*/
/*======================================================================*/

// ADMIN LOGIN PAGE
void admin_log()
{
	char adm_pw[20] = "admin1";		// This is ADMIN Password
	char get_pw[20];
	int rep;

	system("cls");
	realtime();
	printf("\n\n\t\t*** Admin Login Page ***\n");
	printf("\n\t\t___________________");
	printf("\n\t\tEnter the password: ");
	scanf("%s", &get_pw);
	if (strcmp(get_pw, adm_pw) == 0)
	{
		admin_menu();
	}
	else
	{
		printf("\n\tWrong Password!\n\tTry again? [1 = Yes / 0 = No]: ");
		scanf("%d", &rep);
		if (rep == 1)
		{
			admin_log();
			// Program will restart the admin login page
		}
		else if (rep == 0)
		{
			printf("\n\tRedirecting to Main Page...");
			sleep(3000);
			main();
			// Program will back to main page
		}
		else
		{
			printf("\n\tError!\n\tInvalid Input!\n\tBack to Main page...");
			sleep(3000);
			main();
		}
	}
}

// ADMIN MENU PAGE
void admin_menu()
{
	int mnu_op, ext;

	system("cls");
	realtime();
	printf("\n ---------\n | Admin |\n ---------\n");
	printf("\n\n\t\t*** Welcome to Admin Page! ***\n\n\t\tWhat do you want to do?");
	printf("\n\t\t1. Add new record\n\t\t2. Change a record\n\t\t3. Search for a record\n\t\t4. Back to Main Page\n\t\t5. Exit\n");
	printf("\n\t\t_____________");
	printf("\n\t\tEnter option: ");
	scanf("%d", &mnu_op);
	switch (mnu_op)
	{
	case 1:
		admin_add();
		break;
	case 2:
		admin_chg();
		break;
	case 3:
		system("cls");
		realtime();
		printf("\n ---------\n | Admin |\n ---------\n");
		printf("\n\t\t*** Let's Track Someone! ***\n");
		srch();
		printf("\n\n\t\tSearch completed!");
		printf("\n\t\tEnter 1 to return to Admin Menu, Enter 0 to Exit Program: ");
		scanf("%d", &ext);
		if (ext == 1)
		{
			printf("\n\tRedirecting to Admin Menu Page...");
			sleep(2000);
			admin_menu();
		}
		else if (ext == 0)
		{
			exit(0);
		}
		else
		{
			printf("\n\tError!\n\tInvalid input!\n\tExiting the program...");
			sleep(1000);
			exit(0);
		}
		break;
	case 4:
		printf("\n\tRedirecting to Main Page... ");
		sleep(2000);
		main();
		break;
	case 5: exit(0);
	default:
		printf("\n\tError!\n\tInvalid Input!\n\tRefreshing the page...");
		sleep(1000);
		admin_menu();
		break;
	}
}

// ADMIN MENU: ADD
void admin_add()
{
	struct visit data;

	cus_prof(&data);		// Customer Information

	system("cls");
	realtime();
	printf("\n ---------\n | Admin |\n ---------\n");
	cus_serv(&data);		// Service needed

	system("cls");
	realtime();
	printf("\n ---------\n | Admin |\n ---------\n");
	cus_pay(&data);			// Payment information

	visit_id(&data);		// Generating id automatically
	printf("\n\n\tID generated successfully!");
	sleep(1000);

	srvdate(&data);			// Generating date automatically

	write(&data);			// Writing to file
	printf("\n\tA visit record addedd successfully!");
	sleep(1000);
	printf("\n\tRedirecting to Menu Page...");
	sleep(2000);
	admin_menu();
}

// ADMIN MENU: CHANGE
void admin_chg()
{
	int opx;
	system("cls");
	realtime();
	printf("\n ---------\n | Admin |\n ---------\n");
	printf("\n\n\t\tWhat do you want to change?");
	printf("\n\t\t1. Service\n\t\t2. Payment\n\t\t3. Back to Admin Menu");
	printf("\n\n\t\t__________________");
	printf("\n\t\tEnter your option: ");
	scanf("%d", &opx);
	switch (opx)
	{
	case 1:
		system("cls");
		realtime();
		printf("\n ---------\n | Admin |\n ---------\n");
		printf("\n\n\t\t\t*** Let's change the service! ***");
		chng_srv();
		break;

	case 2:
		system("cls");
		realtime();
		printf("\n ---------\n | Admin |\n ---------\n");
		printf("\n\n\t\t\t*** Let's change the payment information! ***");
		chng_pay();
		break;

	case 3:
		printf("\n\tRedirecting to Admin Menu Page...");
		sleep(2000);
		admin_menu();
		break;
	default:
		printf("\n\tError!\n\tInvalid Input!\n");
		sleep(1000);
		printf("\n\tRefreshing The Page...");
		sleep(2000);
		admin_chg();
	}
}

/*======================================================================*/
/*					           ENGINEER				    				*/
/*======================================================================*/

// ENGINEER LOGIN PAGE
void engnr_log()
{
	char eng_pw[20] = "engineer2";		// This is ENGINEER Password
	char get_pw[20];
	int re;

	system("cls");
	realtime();
	printf("\n\n\t\t*** Engineer Login Page ***\n");
	printf("\n\t\t___________________");
	printf("\n\t\tEnter the password: ");
	scanf("%s", &get_pw);
	if (strcmp(get_pw, eng_pw) == 0)
	{
		engnr_menu();
	}
	else
	{
		printf("\n\tWrong Password! \n\tTry again? [1 = Yes / 0 = No]: ");
		scanf("%d", &re);
		if (re == 1)
		{
			engnr_log();
			// Program will restart the admin login page
		}
		else if (re == 0)
		{
			printf("\n\tRedirecting to Main Page...");
			sleep(2000);
			main();
			// Program will back to main page
		}
		else
		{
			printf("\n\tError!\n\tInvalid Input!\n\tBack to Main Page...");
			sleep(2000);
			main();
		}
	}
}

// ENGINEER MENU PAGE
void engnr_menu()
{
	int mn_op, ex;

	system("cls");
	realtime();
	printf("\n ------------\n | Engineer |\n ------------\n");
	printf("\n\n\t\t*** Welcome to Engineer Page! ***\n\n\t\tWhat do you want to do?");
	printf("\n\t\t1. Search for a record\n\t\t2. Change a needed service\n\t\t3. Back to Main Page\n\t\t4. Exit\n");
	printf("\n\t\t_____________");
	printf("\n\t\tEnter option: ");
	scanf("%d", &mn_op);
	switch (mn_op)
	{
	case 1:
		system("cls");
		realtime();
		printf("\n ------------\n | Engineer |\n ------------\n");
		printf("\n\t\t*** Let's Track Someone! ***\n");
		srch();
		printf("\n\n\t\tSearch completed!");
		printf("\n\t\tEnter 1 to return to Engineer Menu, Enter 0 to Exit Program: ");
		scanf("%d", &ex);
		if (ex == 1)
		{
			printf("\n\tRedirecting to Engineer Menu Page...");
			sleep(2000);
			engnr_menu();
		}
		else if (ex == 0)
		{
			exit(0);
		}
		else
		{
			printf("\n\tError!\n\tInvalid input!\n\tTeleporting to Main Page...");
			sleep(1000);
			main();
		}
	case 2:
		system("cls");
		realtime();
		printf("\n ------------\n | Engineer |\n ------------\n");
		printf("\n\n\t\t*** Let's change the service! ***\n");
		engnr_srv();
		break;
	case 3:
		printf("\n\tRedirecting to Main Page... ");
		sleep(2000);
		main();
	default:
		printf("\n\tError!\n\tInvalid Input!\n\tRefreshing the page...");
		sleep(2000);
		engnr_menu();
	}
}

// ENGINEER MENU: CHANGE
void engnr_srv()
{
	char nme[50], type[50], find[50], gender[5];
	int phn, vid, cost, i, find_id;
	char svrc[1000], paym[50];
	int day_st, mon_st, year_st;
	int day_ed, mon_ed, year_ed;
	float paid, bal;
	int conf;
	int step = 0;
	int chk = 0;
	struct visit ch;
	int opl;

	FILE* raw, * tmp_raw, * tmp_res, * report;
	//raw: Real data
	//report: display data
	//tmp_raw: Place for unwanted data, will be appended with modified data and rename as raw
	//tmp_res: Place for wanted data, will be apended at tmp_raw
	//1) unwanted data a> temp_raw, wanted data a> temp_res, unwanted data p> report
	//2) tmp_res > do a change a> tmp_raw  (now temp_raw is contains all data) 
	//3) temp_res a> report (now report contains all data with update date info

	remove("temp_raw.txt");		// To make sure if call the function back, there is no issue
	remove("temp_res.txt");
	remove("report.txt");

	printf("\n\n\t\t____________________");
	printf("\n\t\tEnter Customer Name: ");
	scanf("%s", find);
	printf("\n\t\t\t\t\t\t\t *** ");
	for (i = 0; find[i] != '\0'; i++)
	{
		if (find[i] >= 'a' && find[i] <= 'z')
		{
			find[i] = find[i] - 32;
		}
	}

	raw = fopen("rawdata.txt", "r");
	if (raw == NULL)
	{
		printf("\nFile cannot be opened");
	}


	while (fscanf(raw, "%d %s %d %s %s %d/%d/%d %d/%d/%d %d %s %f %s %f\n", &vid, nme, &phn, gender, svrc, &day_st, &mon_st, &year_st, &day_ed, &mon_ed, &year_ed, &cost, type, &paid, paym, &bal) != EOF)
	{
		if (strcmp(find, nme) == 0)
		{
			step += 1;

			tmp_res = fopen("temp_res.txt", "a");
			if (tmp_res == NULL)
			{
				printf("\nFile cannot be opened");
			}

			// Move found result to temporary file
			fprintf(tmp_res, "%d\t %s\t %d\t %s\t %s\t %d/%d/%d\t %d/%d/%d\t %d\t %s\t %f\t %s\t %f\n", vid, nme, phn, gender, svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed, cost, type, paid, paym, bal);
			// Display on console
			printf("\n\n\t\tVisit No. : %d", vid);
			printf("\n\t\t____________________________________________________________________________________\n");
			printf("\t\tName: %s   Phone: %d   Gender: %s \n", nme, phn, gender);
			printf("\t\t====================================================================================\n");
			printf("\t\t            Service needed                  Start Date              Finish Date     \n");
			printf("\t\t====================================================================================\n");
			printf("\t\t%s\t %02d/%02d/%d\t          %02d/%02d/%d\n", svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed);
			printf("\t\t____________________________________________________________________________________\n");
			printf("\t\tFee: RM %d %s   Total Paid: RM %.2f %s   Total Balance: RM %.2f\n", cost, type, paid, paym, bal);
			printf("\t\t____________________________________________________________________________________\n\n");
			fclose(tmp_res);
		}
		else if (strcmp(find, nme) != 0)
		{
			report = fopen("report.txt", "a");
			if (report == NULL)
			{
				printf("\nFile cannot be opened");
			}
			tmp_raw = fopen("temp_raw.txt", "a");
			if (tmp_raw == NULL)
			{
				printf("\nFile cannot be opened");
			}
			fprintf(tmp_raw, "%d\t %s\t %d\t %s\t %s\t %d/%d/%d\t %d/%d/%d\t %d\t %s\t %f\t %s\t %f\n", vid, nme, phn, gender, svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed, cost, type, paid, paym, bal);
			fprintf(report, "\nVisit No. : %d", vid);
			fprintf(report, "\n____________________________________________________________________________________\n");
			fprintf(report, "Name: %s   Phone: %d   Gender: %s \n", nme, phn, gender);
			fprintf(report, "====================================================================================\n");
			fprintf(report, "            Service needed                  Start Date              Finish Date     \n");
			fprintf(report, "====================================================================================\n");
			fprintf(report, "%s\t %02d/%02d/%d\t          %02d/%02d/%d\n", svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed);
			fprintf(report, "____________________________________________________________________________________\n");
			fprintf(report, "Fee: RM %d %s   Total Paid: RM %.2f %s   Total Balance: RM %.2f\n", cost, type, paid, paym, bal);
			fprintf(report, "____________________________________________________________________________________\n\n");
			fclose(report);
			fclose(tmp_raw);
		}
	}


	fclose(raw);

	// End of sorting wanted and unwanted data
	printf("\n\t\t%d Result(s) Found!", step);

	if (step == 1)													// If only 1 result found
	{
		printf("\n\t\tConfirm this data? [1 = Yes / 0 = No]: ");
		scanf("%d", &conf);
		if (conf == 1)
		{
			system("cls");
			realtime();
			printf("\n ------------\n | Engineer |\n ------------\n");
			printf("\n\t\t*** Please Insert New Data ***\n");

			cus_serv(&ch);			// Service needed
			system("cls");
			realtime();
			printf("\n ------------\n | Engineer |\n ------------\n");
			date_special(&ch);		// Get new date
			srv_update(&ch);		// Update the data   

			printf("\n\tEnter 1 to continue, any key to Exit: ");
			scanf("%d", &opl);
			if (opl == 1)
			{
				printf("\n\tRedirecting to Engineer Menu Page...");
				sleep(2000);
				engnr_menu();
			}
			else
			{
				exit(0);
			}
		}
		else if (conf == 0)
		{
			printf("\n\tPlease search again.");
			sleep(1000);
			printf("\n\tRedirecting to Engineer Menu Page...");
			sleep(2000);
			engnr_menu();
		}
		else
		{
			printf("\n\tError!\n\tInvalid Input!\n\tRedirecting to Engineer Menu Page...");
			sleep(2000);
			engnr_menu();
		}
	}
	else if (step > 1)											// If result found more than one
	{
		printf("\n\n\t\tChoose one from the result by entering the Visit ID");
		printf("\n\t\tVisit ID (NUMBER ONLY): ");
		scanf("%d", &find_id);

		printf("\n\t\t\t\t\t\t\t *** ");
		remove("temp_res.txt");
		raw = fopen("rawdata.txt", "r");
		if (raw == NULL)
		{
			printf("\nFile cannot be opened");
		}
		while (fscanf(raw, "%d %s %d %s %s %d/%d/%d %d/%d/%d %d %s %f %s %f\n", &vid, nme, &phn, gender, svrc, &day_st, &mon_st, &year_st, &day_ed, &mon_ed, &year_ed, &cost, type, &paid, paym, &bal) != EOF)
		{
			if (strcmp(find, nme) == 0 && find_id == vid)
			{
				chk += 1;
				tmp_res = fopen("temp_res.txt", "a");
				if (tmp_res == NULL)
				{
					printf("\nFile cannot be opened");
				}

				// Move found result to temporary file
				fprintf(tmp_res, "%d\t %s\t %d\t %s\t %s\t %d/%d/%d\t %d/%d/%d\t %d\t %s\t %.2f\t %s\t %.2f\n", vid, nme, phn, gender, svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed, cost, type, paid, paym, bal);
				// Display on console
				printf("\n\n\t\tVisit No. : %d", vid);
				printf("\n\t\t____________________________________________________________________________________\n");
				printf("\t\tName: %s   Phone: %d   Gender: %s \n", nme, phn, gender);
				printf("\t\t====================================================================================\n");
				printf("\t\t            Service needed                  Start Date              Finish Date     \n");
				printf("\t\t====================================================================================\n");
				printf("\t\t%s\t %02d/%02d/%d\t          %02d/%02d/%d\n", svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed);
				printf("\t\t____________________________________________________________________________________\n");
				printf("\t\tFee: RM %d %s   Total Paid: RM %.2f %s   Total Balance: RM %.2f\n", cost, type, paid, paym, bal);
				printf("\t\t____________________________________________________________________________________\n\n");
				fclose(tmp_res);
			}
			else if (strcmp(find, nme) == 0 && find_id != vid)
			{
				tmp_raw = fopen("temp_raw.txt", "a");
				if (tmp_raw == NULL)
				{
					printf("\nFile cannot be opened");
				}
				report = fopen("report.txt", "a");
				if (report == NULL)
				{
					printf("\nFile cannot be opened");
				}

				fprintf(tmp_raw, "%d\t %s\t %d\t %s\t %s\t %d/%d/%d\t %d/%d/%d\t %d\t %s\t %.2f\t %s\t %.2f\n", vid, nme, phn, gender, svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed, cost, type, paid, paym, bal);

				fprintf(report, "\nVisit No. : %d", vid);
				fprintf(report, "\n____________________________________________________________________________________\n");
				fprintf(report, "Name: %s   Phone: %d   Gender: %s \n", nme, phn, gender);
				fprintf(report, "====================================================================================\n");
				fprintf(report, "            Service needed                  Start Date              Finish Date     \n");
				fprintf(report, "====================================================================================\n");
				fprintf(report, "%s\t %02d/%02d/%d\t          %02d/%02d/%d\n", svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed);
				fprintf(report, "____________________________________________________________________________________\n");
				fprintf(report, "Fee: RM %d %s   Total Paid: RM %.2f %s   Total Balance: RM %.2f\n", cost, type, paid, paym, bal);
				fprintf(report, "____________________________________________________________________________________\n\n");

				fclose(tmp_raw);
				fclose(report);
			}
		}
		fclose(raw);
		if (chk == 1)
		{
			printf("\n\t\tYay! Data Found!");
			printf("\n\t\tContinue? [1 = Yes / 0 = No]: ");
			scanf("%d", &conf);
			if (conf == 1)
			{
				system("cls");
				realtime();
				printf("\n ------------\n | Engineer |\n ------------\n");
				printf("\n\t\t*** Please Insert New Data ***\n");

				cus_serv(&ch);			// Service needed
				system("cls");
				realtime();
				printf("\n ------------\n | Engineer |\n ------------\n");
				date_special(&ch);		// Get new date
				srv_update(&ch);		// Update the data
				printf("\n\n\tEnter 1 to continue, any key to Exit: ");
				scanf("%d", &opl);
				if (opl == 1)
				{
					printf("\n\tRedirecting to Engineer Menu Page...");
					sleep(2000);
					engnr_menu();
				}
				else
				{
					exit(0);
				}
			}
			else if (conf == 0)
			{
				printf("\n\tPlease try again.");
				sleep(1000);
				printf("\n\tRedirecting to Engineer Menu Page...");
				sleep(2000);
				engnr_menu();
			}
			else
			{
				printf("\n\tError!\n\tInvalid Input!\n\tRedirecting to Engineer Menu Page...");
				sleep(2000);
				engnr_menu();
			}
		}
		else if (chk == 0)
		{
			printf("\n\t\tOh No.. \n\t\tYour data is not here..\n\t\tLooks like you enter wrong input!\n");
			sleep(1000);
			printf("\n\n\tPlease try again.\n\tRedirecting to Engineer Menu Page...");
			sleep(2000);
			engnr_menu();
		}
	}
	else				// If result is 0
	{
		printf("\n\n\tInvalid Input!\n\tPlease try again.\n\tRedirecting to Engineer Menu Page...");
		sleep(2000);
		engnr_menu();
	}
}

/*======================================================================*/
/*					     SUPPORTING FUNCTIONS		    				*/
/*======================================================================*/

// [GLOBAL] Delay function
void sleep(unsigned ms)
{
	Sleep(ms);
}

// [GLOBAL] Time function
int realtime()
{

	time_t t;
	time(&t);

	printf("Today is:\n%s", ctime(&t));

	return 0;
}

// [GLOBAL] Date exceptional
int date_special(struct visit* v)			//The parameter will accept pointer 
{
	int oddmon[7] = { 1,3,5,7,8,10,12 };
	int evenmon[4] = { 4,6,9,11 };
	int y_feb, i;

	system("cls");
	realtime();
	printf("\n ---------\n | Admin |\n ---------\n");
	printf("\n\t\tEnter the new start date (NUMBER ONLY): ");
	printf("\n\t\t_______________________________________");
	printf("\n\n\t\tDay (dd): ");
	scanf("%d", &v->dd_st);
	printf("\n\t\tMonth (mm): ");
	scanf("%d", &v->mm_st);
	printf("\n\t\tYear (yyyy): ");
	scanf("%d", &v->yy_st);

	if (v->mm_st > 12)
	{
		printf("\n\t\tYou know we only have 12 months, right?");
		printf("\n\t\tPlease try again...");
		sleep(2000);
		remove("temp_res.txt");
		remove("temp_raw.txt");
		admin_chg();
	}
	else
	{
		// For December
		if (v->mm_st == 12)
		{
			if (v->dd_st > 31)
			{
				printf("\n\t\tYou know we only have 31 days in December, right?");
				printf("\n\t\tPlease try again...");
				sleep(2000);
				admin_chg();
			}
			else if (v->dd_st == 31 && v->days > 0)
			{
				v->dd_ed = (v->dd_st + v->days) - 31;
				v->yy_ed = v->yy_st + 1;
				v->mm_ed = 1;
			}
			else
			{
				v->dd_ed = v->dd_st + v->days;
				v->mm_ed = v->mm_st;
				v->yy_ed = v->yy_st;
			}
		}
		// For February
		else if (v->mm_st == 2)
		{
			do
			{
				y_feb = v->yy_st - 4;
			} while (y_feb > 0);

			if (y_feb == 0)		// 29 days for every 4 years
			{
				if (v->dd_st > 29)
				{
					printf("\n\t\tYou know we only have 29 days in February this year, right?");
					printf("\n\t\tPlease try again...");
					sleep(2000);
					admin_chg();
				}
				else if (v->dd_st == 29 && v->days > 0)
				{
					v->dd_ed = (v->dd_st + v->days) - 29;
					v->mm_ed = v->mm_st + 1;
					v->yy_ed = v->yy_st;
				}
				else
				{
					v->dd_ed = v->dd_st + v->days;
					v->mm_ed = v->mm_st;
					v->yy_ed = v->yy_st;
				}
			}
			else				// 28 days for the rest
			{
				if (v->dd_st > 28)
				{
					printf("\n\t\tYou know we only have 28 days in February this year, right?");
					printf("\n\t\tPlease try again...");
					sleep(2000);
					admin_chg();
				}
				else if (v->dd_st == 28 && v->days > 0)
				{
					v->dd_ed = (v->dd_st + v->days) - 28;
					v->mm_ed = v->mm_st + 1;
					v->yy_ed = v->yy_st;
				}
				else
				{
					v->dd_ed = v->dd_st + v->days;
					v->mm_ed = v->mm_st;
					v->yy_ed = v->yy_st;
				}
			}
		}
		// Other months
		else
		{
			for (i = 0; i <= 7; i++)
			{
				if (v->mm_st == oddmon[i])			// For months with 31 days
				{
					if (v->dd_st > 31)
					{
						printf("\n\t\tYou know we only have 31 days in this month, right?");
						printf("\n\t\tPlease try again...");
						sleep(2000);
						admin_chg();
					}
					else if (v->dd_st == 31 && v->days > 0)
					{
						v->dd_ed = (v->dd_st + v->days) - 31;
						v->mm_ed = v->mm_st + 1;
						v->yy_ed = v->yy_st;
					}
					else
					{
						v->dd_ed = v->dd_st + v->days;
						v->mm_ed = v->mm_st;
						v->yy_ed = v->yy_st;
					}
				}
				else if (v->mm_st == evenmon[i])	// For months with 30 days
				{
					if (v->dd_st > 30)
					{
						printf("\n\t\tYou know we only have 30 days in this month, right?");
						printf("\n\t\tPlease try again...");
						sleep(2000);
						admin_chg();
					}
					else if (v->dd_st == 30 && v->days > 0)
					{
						v->dd_ed = (v->dd_st + v->days) - 30;
						v->mm_ed = v->mm_st + 1;
						v->yy_ed = v->yy_st;
					}
					else
					{
						v->dd_ed = v->dd_st + v->days;
						v->mm_ed = v->mm_st;
						v->yy_ed = v->yy_st;
					}
				}
			}
		}
	}
	return 0;								// The program runs successfully
}

// [GLOBAL] Search Function
void srch()
{
	char nme[50], type[50], find[50], gender[5];
	int phn, vid, cost, i;
	char svrc[1000], paym[50];
	int day_st, mon_st, year_st;
	int day_ed, mon_ed, year_ed;
	float paid, bal;
	int stp = 0;

	FILE* raw;

	printf("\n\n\t\t____________________");
	printf("\n\t\tEnter Customer Name: ");
	scanf("%s", find);
	for (i = 0; find[i] != '\0'; i++)
	{
		if (find[i] >= 'a' && find[i] <= 'z')
		{
			find[i] = find[i] - 32;
		}
	}

	raw = fopen("rawdata.txt", "r");
	if (raw == NULL)
	{
		printf("\nFile cannot open");
	}

	while (fscanf(raw, "%d %s %d %s %s %d/%d/%d %d/%d/%d %d %s %f %s %f\n", &vid, nme, &phn, gender, svrc, &day_st, &mon_st, &year_st, &day_ed, &mon_ed, &year_ed, &cost, type, &paid, paym, &bal) != EOF)
	{
		/*res = strcmp(find, nme);
		if (res == 0)*/
		if (strcmp(find, nme) == 0)
		{
			stp += 1;
			printf("\n\t\tVisit No. : %d", vid);
			printf("\n\t\t____________________________________________________________________________________\n");
			printf("\t\tName: %s   Phone: %d   Gender: %s \n", nme, phn, gender);
			printf("\t\t====================================================================================\n");
			printf("\t\t            Service needed                  Start Date              Finish Date     \n");
			printf("\t\t====================================================================================\n");
			printf("\t\t%s\t %02d/%02d/%d\t          %02d/%02d/%d\n", svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed);
			printf("\t\t____________________________________________________________________________________\n");
			printf("\t\tFee: RM %d %s   Total Paid: RM %.2f %s   Total Balance: RM %.2f\n", cost, type, paid, paym, bal);
			printf("\t\t____________________________________________________________________________________\n\n");
		}
	}
	fclose(raw);
	if (stp == 0)
	{
		printf("\n\t\tSorry, Result Not Found...");
		printf("\n\t\tPlease try again.");
		sleep(2000);
		srch();
	}
}

// [GLOBAL] Updating service change
void srv_update(struct visit* v)
{
	int vid, phn, cost;
	char gender[20], nme[50], svrc[1000], type[20], paym[20];
	int day_st, mon_st, year_st;
	int day_ed, mon_ed, year_ed;
	float paid, bal;

	FILE* tmp_res, * tmp_raw, * report;

	tmp_res = fopen("temp_res.txt", "r");
	if (tmp_res == NULL)
	{
		printf("\nFile cannot be opened");
	}
	tmp_raw = fopen("temp_raw.txt", "a");
	if (tmp_raw == NULL)
	{
		printf("\nFile cannot be opened");
	}
	report = fopen("report.txt", "a");
	if (report == NULL)
	{
		printf("\nFile cannot be opened");
	}

	fscanf(tmp_res, "%d %s %d %s %s %d/%d/%d %d/%d/%d %d %s %f %s %f\n", &vid, nme, &phn, gender, svrc, &day_st, &mon_st, &year_st, &day_ed, &mon_ed, &year_ed, &cost, type, &paid, paym, &bal);
	v->balnc = paid - v->fee;
	fprintf(tmp_raw, "%d\t %s\t %d\t %s\t %s\t %d/%d/%d\t %d/%d/%d\t %d\t %s\t %.2f\t %s\t %.2f\n", vid, nme, phn, gender, v->serv, v->dd_st, v->mm_st, v->yy_st, v->dd_ed, v->mm_ed, v->yy_ed, v->fee, type, paid, paym, v->balnc);
	fclose(tmp_res);
	fclose(tmp_raw);

	remove("rawdata.txt");
	rename("temp_raw.txt", "rawdata.txt");

	remove("temp_res.txt");  // Remove the unchanged data
	tmp_res = fopen("temp_res.txt", "a");
	if (tmp_res == NULL)
	{
		printf("\nFile cannot be opened");
	}
	// Print the changed data
	fprintf(tmp_res, "%d\t %s\t %d\t %s\t %s\t %d/%d/%d\t %d/%d/%d\t %d\t %s\t %.2f\t %s\t %.2f\n", vid, nme, phn, gender, v->serv, v->dd_st, v->mm_st, v->yy_st, v->dd_ed, v->mm_ed, v->yy_ed, v->fee, type, paid, paym, v->balnc);
	fclose(tmp_res);

	// Open again to update the report file
	tmp_res = fopen("temp_res.txt", "r");
	if (tmp_res == NULL)
	{
		printf("\nFile cannot be opened");
	}
	fscanf(tmp_res, "%d %s %d %s %s %d/%d/%d %d/%d/%d %d %s %f %s %f\n", &vid, nme, &phn, gender, svrc, &day_st, &mon_st, &year_st, &day_ed, &mon_ed, &year_ed, &cost, type, &paid, paym, &bal);

	time_t dt = time(NULL);
	struct tm date = *localtime(&dt);
	int dat, man, ye;
	dat = date.tm_mday;
	man = date.tm_mon + 1;
	ye = date.tm_year + 1900;
	fprintf(report, "\n[Updated on: %d/%d/%d]", dat, man, ye);
	fprintf(report, "\nVisit No. : %d", vid);
	fprintf(report, "\n____________________________________________________________________________________\n");
	fprintf(report, "Name: %s   Phone: %d   Gender: %s \n", nme, phn, gender);
	fprintf(report, "====================================================================================\n");
	fprintf(report, "            Service needed                  Start Date              Finish Date     \n");
	fprintf(report, "====================================================================================\n");
	fprintf(report, "%s\t %02d/%02d/%d\t          %02d/%02d/%d\n", svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed);
	fprintf(report, "____________________________________________________________________________________\n");
	fprintf(report, "Fee: RM %d %s   Total Paid: RM %.2f %s   Total Balance: RM %.2f\n", cost, type, paid, paym, bal);
	fprintf(report, "____________________________________________________________________________________\n\n");
	fclose(tmp_res);
	fclose(report);
	remove("temp_res.txt");

	printf("\n\n\tRecord Updated Successfully!");
}

// [GLOBAL] Change Service		
void chng_srv()
{
	char nme[50], type[50], find[50], gender[5];
	int phn, vid, cost, i, find_id;
	char svrc[1000], paym[50];
	int day_st, mon_st, year_st;
	int day_ed, mon_ed, year_ed;
	float paid, bal;
	int conf;
	int step = 0;
	int chk = 0;

	FILE* raw, * tmp_raw, * tmp_res, * report;
	//raw: Real data
	//report: display data
	//tmp_raw: Place for unwanted data, will be appended with modified data and rename as raw
	//tmp_res: Place for wanted data, will be apended at tmp_raw
	//1) unwanted data a> temp_raw, wanted data a> temp_res, unwanted data p> report
	//2) tmp_res > do a change a> tmp_raw  (now temp_raw is contains all data) 
	//3) temp_res a> report (now report contains all data with update date info

	remove("temp_raw.txt");		// To make sure if call the function back, there is no issue
	remove("temp_res.txt");
	remove("report.txt");

	printf("\n\n\t\t____________________");
	printf("\n\t\tEnter Customer Name: ");
	scanf("%s", find);
	printf("\n\t\t\t\t\t\t\t *** ");
	for (i = 0; find[i] != '\0'; i++)
	{
		if (find[i] >= 'a' && find[i] <= 'z')
		{
			find[i] = find[i] - 32;
		}
	}

	raw = fopen("rawdata.txt", "r");
	if (raw == NULL)
	{
		printf("\nFile cannot be opened");
	}

	//DONT TOUCH
	while (fscanf(raw, "%d %s %d %s %s %d/%d/%d %d/%d/%d %d %s %f %s %f\n", &vid, nme, &phn, gender, svrc, &day_st, &mon_st, &year_st, &day_ed, &mon_ed, &year_ed, &cost, type, &paid, paym, &bal) != EOF)
	{
		if (strcmp(find, nme) == 0)
		{
			step += 1;

			tmp_res = fopen("temp_res.txt", "a");
			if (tmp_res == NULL)
			{
				printf("\nFile cannot be opened");
			}

			// Move found result to temporary file
			fprintf(tmp_res, "%d\t %s\t %d\t %s\t %s\t %d/%d/%d\t %d/%d/%d\t %d\t %s\t %f\t %s\t %f\n", vid, nme, phn, gender, svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed, cost, type, paid, paym, bal);
			// Display on console
			printf("\n\n\t\tVisit No. : %d", vid);
			printf("\n\t\t____________________________________________________________________________________\n");
			printf("\t\tName: %s   Phone: %d   Gender: %s \n", nme, phn, gender);
			printf("\t\t====================================================================================\n");
			printf("\t\t            Service needed                  Start Date              Finish Date     \n");
			printf("\t\t====================================================================================\n");
			printf("\t\t%s\t %02d/%02d/%d\t          %02d/%02d/%d\n", svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed);
			printf("\t\t____________________________________________________________________________________\n");
			printf("\t\tFee: RM %d %s   Total Paid: RM %.2f %s   Total Balance: RM %.2f\n", cost, type, paid, paym, bal);
			printf("\t\t____________________________________________________________________________________\n\n");
			fclose(tmp_res);
		}
		else if (strcmp(find, nme) != 0)
		{
			report = fopen("report.txt", "a");
			if (report == NULL)
			{
				printf("\nFile cannot be opened");
			}
			tmp_raw = fopen("temp_raw.txt", "a");
			if (tmp_raw == NULL)
			{
				printf("\nFile cannot be opened");
			}
			fprintf(tmp_raw, "%d\t %s\t %d\t %s\t %s\t %d/%d/%d\t %d/%d/%d\t %d\t %s\t %f\t %s\t %f\n", vid, nme, phn, gender, svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed, cost, type, paid, paym, bal);
			fprintf(report, "\nVisit No. : %d", vid);
			fprintf(report, "\n____________________________________________________________________________________\n");
			fprintf(report, "Name: %s   Phone: %d   Gender: %s \n", nme, phn, gender);
			fprintf(report, "====================================================================================\n");
			fprintf(report, "            Service needed                  Start Date              Finish Date     \n");
			fprintf(report, "====================================================================================\n");
			fprintf(report, "%s\t %02d/%02d/%d\t          %02d/%02d/%d\n", svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed);
			fprintf(report, "____________________________________________________________________________________\n");
			fprintf(report, "Fee: RM %d %s   Total Paid: RM %.2f %s   Total Balance: RM %.2f\n", cost, type, paid, paym, bal);
			fprintf(report, "____________________________________________________________________________________\n\n");
			fclose(report);
			fclose(tmp_raw);
		}
	}
	fclose(raw);

	// End of sorting wanted and unwanted data
	printf("\n\t\t%d Result(s) Found!", step);

	if (step == 1)													// If only 1 result found
	{
		printf("\n\t\tConfirm this data? [1 = Yes / 0 = No]: ");
		scanf("%d", &conf);
		if (conf == 1)
		{
			system("cls");
			realtime();
			printf("\n ---------\n | Admin |\n ---------\n");
			printf("\n\t\t*** Please Insert New Data ***\n");
			struct visit ch;
			int opl;

			cus_serv(&ch);			// Service needed
			system("cls");
			realtime();
			printf("\n ---------\n | Admin |\n ---------\n");
			date_special(&ch);		// Get new date
			srv_update(&ch);		// Update the data   

			printf("\n\tEnter 1 to continue, any key to Exit: ");
			scanf("%d", &opl);
			if (opl == 1)
			{
				printf("\n\tRedirecting to Admin Change Page...");
				sleep(2000);
				admin_chg();
			}
			else
			{
				exit(0);
			}
		}
		else if (conf == 0)
		{
			printf("\n\tPlease search again.");
			sleep(1000);
			printf("\n\tRedirecting to Admin Change Page...");
			sleep(2000);
			admin_chg();
		}
		else
		{
			printf("\n\tError!\n\tInvalid Input!\n\tRedirecting to Admin Change Page...");
			sleep(2000);
			admin_chg();
		}
	}
	else if (step > 1)											// If result found more than one
	{
		printf("\n\n\t\tChoose one from the result by entering the Visit ID");
		printf("\n\t\tVisit ID (NUMBER ONLY): ");
		scanf("%d", &find_id);

		printf("\n\t\t\t\t\t\t\t *** ");
		remove("temp_res.txt");
		raw = fopen("rawdata.txt", "r");
		if (raw == NULL)
		{
			printf("\nFile cannot be opened");
		}
		while (fscanf(raw, "%d %s %d %s %s %d/%d/%d %d/%d/%d %d %s %f %s %f\n", &vid, nme, &phn, gender, svrc, &day_st, &mon_st, &year_st, &day_ed, &mon_ed, &year_ed, &cost, type, &paid, paym, &bal) != EOF)
		{
			if (strcmp(find, nme) == 0 && find_id == vid)
			{
				chk += 1;
				tmp_res = fopen("temp_res.txt", "a");
				if (tmp_res == NULL)
				{
					printf("\nFile cannot be opened");
				}

				// Move found result to temporary file
				fprintf(tmp_res, "%d\t %s\t %d\t %s\t %s\t %d/%d/%d\t %d/%d/%d\t %d\t %s\t %.2f\t %s\t %.2f\n", vid, nme, phn, gender, svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed, cost, type, paid, paym, bal);
				// Display on console
				printf("\n\n\t\tVisit No. : %d", vid);
				printf("\n\t\t____________________________________________________________________________________\n");
				printf("\t\tName: %s   Phone: %d   Gender: %s \n", nme, phn, gender);
				printf("\t\t====================================================================================\n");
				printf("\t\t            Service needed                  Start Date              Finish Date     \n");
				printf("\t\t====================================================================================\n");
				printf("\t\t%s\t %02d/%02d/%d\t          %02d/%02d/%d\n", svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed);
				printf("\t\t____________________________________________________________________________________\n");
				printf("\t\tFee: RM %d %s   Total Paid: RM %.2f %s   Total Balance: RM %.2f\n", cost, type, paid, paym, bal);
				printf("\t\t____________________________________________________________________________________\n\n");
				fclose(tmp_res);
			}
			else if (strcmp(find, nme) == 0 && find_id != vid)
			{
				tmp_raw = fopen("temp_raw.txt", "a");
				if (tmp_raw == NULL)
				{
					printf("\nFile cannot be opened");
				}
				report = fopen("report.txt", "a");
				if (report == NULL)
				{
					printf("\nFile cannot be opened");
				}

				fprintf(tmp_raw, "%d\t %s\t %d\t %s\t %s\t %d/%d/%d\t %d/%d/%d\t %d\t %s\t %.2f\t %s\t %.2f\n", vid, nme, phn, gender, svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed, cost, type, paid, paym, bal);

				fprintf(report, "\nVisit No. : %d", vid);
				fprintf(report, "\n____________________________________________________________________________________\n");
				fprintf(report, "Name: %s   Phone: %d   Gender: %s \n", nme, phn, gender);
				fprintf(report, "====================================================================================\n");
				fprintf(report, "            Service needed                  Start Date              Finish Date     \n");
				fprintf(report, "====================================================================================\n");
				fprintf(report, "%s\t %02d/%02d/%d\t          %02d/%02d/%d\n", svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed);
				fprintf(report, "____________________________________________________________________________________\n");
				fprintf(report, "Fee: RM %d %s   Total Paid: RM %.2f %s   Total Balance: RM %.2f\n", cost, type, paid, paym, bal);
				fprintf(report, "____________________________________________________________________________________\n\n");

				fclose(tmp_raw);
				fclose(report);
			}
		}
		fclose(raw);
		if (chk == 1)
		{
			printf("\n\t\tYay! Data Found!");
			printf("\n\t\tContinue? [1 = Yes / 0 = No]: ");
			scanf("%d", &conf);
			if (conf == 1)
			{
				system("cls");
				realtime();
				printf("\n ---------\n | Admin |\n ---------\n");
				printf("\n\t\t*** Please Insert New Data ***\n");
				struct visit ch;
				int opl;

				cus_serv(&ch);			// Service needed
				system("cls");
				realtime();
				printf("\n ---------\n | Admin |\n ---------\n");
				date_special(&ch);		// Get new date
				srv_update(&ch);		// Update the data
				printf("\n\n\tEnter 1 to continue, any key to Exit: ");
				scanf("%d", &opl);
				if (opl == 1)
				{
					printf("\n\tRedirecting to Admin Change Page...");
					sleep(2000);
					admin_chg();
				}
				else
				{
					exit(0);
				}

			}
			else if (conf == 0)
			{
				printf("\n\tPlease try again.");
				sleep(1000);
				printf("\n\tRedirecting to Admin Change Page...");
				sleep(2000);
				admin_chg();
				// Program will refresh the page
			}
			else
			{
				printf("\n\tError!\n\tInvalid Input!\n\tTeleporting to Admin Change Page...");
				sleep(2000);
				admin_chg();
				// Program will go to admin change page
			}
		}
		else if (chk == 0)
		{
			printf("\n\t\tOh No.. \n\t\tYour data is not here..\n\t\tLooks like you enter wrong input!\n");
			sleep(1000);
			printf("\n\n\tPlease try again.\n\tTeleporting back to Admin Change Page...");
			sleep(2000);
			admin_chg();
		}
	}
	else				// If result is 0
	{
		printf("\n\n\tInvalid Input!\n\tPlease try again.\n\tRedirecting back to Admin Change Page...");
		sleep(2000);
		admin_chg();
	}
}


// [ADMIN] Updating payment information
void pay_update(struct visit* v)		// To move temp result to temp raw
{
	int vid, phn, cost;
	char gender[20], nme[50], svrc[1000], type[20], paym[20];
	int day_st, mon_st, year_st;
	int day_ed, mon_ed, year_ed;
	float paid, bal;

	FILE* tmp_res, * tmp_raw, * report;
	tmp_res = fopen("temp_res.txt", "r");
	if (tmp_res == NULL)
	{
		printf("\nFile cannot be opened");
	}
	tmp_raw = fopen("temp_raw.txt", "a");
	if (tmp_raw == NULL)
	{
		printf("\nFile cannot be opened");
	}
	report = fopen("report.txt", "a");
	if (report == NULL)
	{
		printf("\nFile cannot be opened");
	}

	fscanf(tmp_res, "%d %s %d %s %s %d/%d/%d %d/%d/%d %d %s %f %s %f\n", &vid, nme, &phn, gender, svrc, &day_st, &mon_st, &year_st, &day_ed, &mon_ed, &year_ed, &cost, type, &paid, paym, &bal);
	fprintf(tmp_raw, "%d\t %s\t %d\t %s\t %s\t %d/%d/%d\t %d/%d/%d\t %d\t %s\t %.2f\t %s\t %.2f\n", vid, nme, phn, gender, svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed, cost, type, v->paid, v->paym, v->balnc);
	fclose(tmp_res);
	fclose(tmp_raw);

	remove("temp_res.txt");
	tmp_res = fopen("temp_res.txt", "a");
	if (tmp_res == NULL)
	{
		printf("\nFile cannot be opened");
	}
	fprintf(tmp_res, "%d %s %d %s %s %d/%d/%d %d/%d/%d %d %s %f %s %f\n", vid, nme, phn, gender, svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed, cost, type, v->paid, v->paym, v->balnc);
	remove("rawdata.txt");
	rename("temp_raw.txt", "rawdata.txt");
	fclose(tmp_res);

	tmp_res = fopen("temp_res.txt", "r");
	if (tmp_res == NULL)
	{
		printf("\nFile cannot be opened");
	}
	fscanf(tmp_res, "%d %s %d %s %s %d/%d/%d %d/%d/%d %d %s %f %s %f\n", &vid, nme, &phn, gender, svrc, &day_st, &mon_st, &year_st, &day_ed, &mon_ed, &year_ed, &cost, type, &paid, paym, &bal);

	time_t dt = time(NULL);
	struct tm date = *localtime(&dt);
	int dat, man, ye;
	dat = date.tm_mday;
	man = date.tm_mon + 1;
	ye = date.tm_year + 1900;
	fprintf(report, "\n[Updated on: %d/%d/%d]", dat, man, ye);
	fprintf(report, "\nVisit No. : %d", vid);
	fprintf(report, "\n____________________________________________________________________________________\n");
	fprintf(report, "Name: %s   Phone: %d   Gender: %s \n", nme, phn, gender);
	fprintf(report, "====================================================================================\n");
	fprintf(report, "            Service needed                  Start Date              Finish Date     \n");
	fprintf(report, "====================================================================================\n");
	fprintf(report, "%s\t %02d/%02d/%d\t          %02d/%02d/%d\n", svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed);
	fprintf(report, "____________________________________________________________________________________\n");
	fprintf(report, "Fee: RM %d %s   Total Paid: RM %.2f %s   Total Balance: RM %.2f\n", cost, type, paid, paym, bal);
	fprintf(report, "____________________________________________________________________________________\n\n");
	fclose(tmp_res);
	fclose(report);
	remove("temp_res.txt");
	printf("\n\n\tRecord Updated Successfully!");
}

// [ADMIN] Change Payment Information
void chng_pay()
{
	char nme[50], type[50], find[50], gender[5];
	int phn, vid, cost, i, find_id;
	char svrc[1000], paym[50];
	int day_st, mon_st, year_st;
	int day_ed, mon_ed, year_ed;
	float paid, bal;
	int conf;
	int step = 0;
	int chk = 0;
	struct visit ch;
	int opl;

	FILE* raw, * tmp_raw, * tmp_res, * report;
	//raw: Real data
	//report: display data
	//tmp_raw: Place for unwanted data, will be appended with modified data and rename as raw
	//tmp_res: Place for wanted data, will be apended at tmp_raw
	//1) unwanted data a> temp_raw, wanted data a> temp_res, unwanted data p> report
	//2) tmp_res > do a change a> tmp_raw  (now temp_raw is contains all data) 
	//3) temp_res a> report (now report contains all data with update date info

	remove("temp_raw.txt");		// To make sure if call the function back, there is no issue
	remove("temp_res.txt");
	remove("report.txt");

	printf("\n\n\t\t____________________");
	printf("\n\t\tEnter Customer Name: ");
	scanf("%s", find);
	printf("\n\t\t\t\t\t\t\t *** ");
	for (i = 0; find[i] != '\0'; i++)
	{
		if (find[i] >= 'a' && find[i] <= 'z')
		{
			find[i] = find[i] - 32;
		}
	}

	raw = fopen("rawdata.txt", "r");
	if (raw == NULL)
	{
		printf("\nFile cannot be opened");
	}

	//DONT TOUCH
	while (fscanf(raw, "%d %s %d %s %s %d/%d/%d %d/%d/%d %d %s %f %s %f\n", &vid, nme, &phn, gender, svrc, &day_st, &mon_st, &year_st, &day_ed, &mon_ed, &year_ed, &cost, type, &paid, paym, &bal) != EOF)
	{
		if (strcmp(find, nme) == 0)
		{
			step += 1;

			tmp_res = fopen("temp_res.txt", "a");
			if (tmp_res == NULL)
			{
				printf("\nFile cannot be opened");
			}

			// Move found result to temporary file
			fprintf(tmp_res, "%d\t %s\t %d\t %s\t %s\t %d/%d/%d\t %d/%d/%d\t %d\t %s\t %f\t %s\t %f\n", vid, nme, phn, gender, svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed, cost, type, paid, paym, bal);
			// Display on console
			printf("\n\n\t\tVisit No. : %d", vid);
			printf("\n\t\t____________________________________________________________________________________\n");
			printf("\t\tName: %s   Phone: %d   Gender: %s \n", nme, phn, gender);
			printf("\t\t====================================================================================\n");
			printf("\t\t            Service needed                  Start Date              Finish Date     \n");
			printf("\t\t====================================================================================\n");
			printf("\t\t%s\t %02d/%02d/%d\t          %02d/%02d/%d\n", svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed);
			printf("\t\t____________________________________________________________________________________\n");
			printf("\t\tFee: RM %d %s   Total Paid: RM %.2f %s   Total Balance: RM %.2f\n", cost, type, paid, paym, bal);
			printf("\t\t____________________________________________________________________________________\n\n");
			fclose(tmp_res);
		}
		else if (strcmp(find, nme) != 0)
		{
			report = fopen("report.txt", "a");
			if (report == NULL)
			{
				printf("\nFile cannot be opened");
			}
			tmp_raw = fopen("temp_raw.txt", "a");
			if (tmp_raw == NULL)
			{
				printf("\nFile cannot be opened");
			}
			fprintf(tmp_raw, "%d\t %s\t %d\t %s\t %s\t %d/%d/%d\t %d/%d/%d\t %d\t %s\t %f\t %s\t %f\n", vid, nme, phn, gender, svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed, cost, type, paid, paym, bal);
			fprintf(report, "\nVisit No. : %d", vid);
			fprintf(report, "\n____________________________________________________________________________________\n");
			fprintf(report, "Name: %s   Phone: %d   Gender: %s \n", nme, phn, gender);
			fprintf(report, "====================================================================================\n");
			fprintf(report, "            Service needed                  Start Date              Finish Date     \n");
			fprintf(report, "====================================================================================\n");
			fprintf(report, "%s\t %02d/%02d/%d\t          %02d/%02d/%d\n", svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed);
			fprintf(report, "____________________________________________________________________________________\n");
			fprintf(report, "Fee: RM %d %s   Total Paid: RM %.2f %s   Total Balance: RM %.2f\n", cost, type, paid, paym, bal);
			fprintf(report, "____________________________________________________________________________________\n\n");
			fclose(report);
			fclose(tmp_raw);
		}
	}
	fclose(raw);

	// End of sorting wanted and unwanted data
	printf("\n\t\t%d Result(s) Found!", step);

	if (step == 1)													// If only 1 result found
	{
		printf("\n\t\tConfirm this data? [1 = Yes / 0 = No]: ");
		scanf("%d", &conf);
		if (conf == 1)
		{
			system("cls");
			realtime();
			printf("\n ---------\n | Admin |\n ---------\n");
			printf("\n\t\t*** Please Insert New Data ***\n");

			tmp_res = fopen("temp_res.txt", "r");
			if (tmp_res == NULL)
			{
				printf("\nFile cannot be opened");
			}
			fscanf(tmp_res, "%d %s %d %s %s %d/%d/%d %d/%d/%d %d %s %f %s %f\n", &vid, nme, &phn, gender, svrc, &day_st, &mon_st, &year_st, &day_ed, &mon_ed, &year_ed, &cost, type, &paid, paym, &bal);
			ch.fee = cost;
			fclose(tmp_res);
			cus_pay(&ch);			// Payment information
			system("cls");
			realtime();
			printf("\n ---------\n | Admin |\n ---------\n");
			date_special(&ch);		// Get new date
			pay_update(&ch);		// Update the data   

			printf("\n\tEnter 1 to continue, any key to Exit: ");
			scanf("%d", &opl);
			if (opl == 1)
			{
				printf("\n\tRedirecting to Admin Change Page...");
				sleep(2000);
				admin_chg();
			}
			else
			{
				exit(0);
			}
		}
		else if (conf == 0)
		{
			printf("\n\tPlease search again.");
			sleep(1000);
			printf("\n\tRedirecting to Admin Change Page...");
			sleep(2000);
			admin_chg();
		}
		else
		{
			printf("\n\tError!\n\tInvalid Input!\n\tRedirecting to Admin Change Page...");
			sleep(2000);
			admin_chg();
		}
	}
	else if (step > 1)											// If result found more than one
	{
		printf("\n\n\t\tChoose one from the result by entering the Visit ID");
		printf("\n\t\tVisit ID (NUMBER ONLY): ");
		scanf("%d", &find_id);

		printf("\n\t\t\t\t\t\t\t *** ");
		remove("temp_res.txt");
		raw = fopen("rawdata.txt", "r");
		if (raw == NULL)
		{
			printf("\nFile cannot be opened");
		}
		while (fscanf(raw, "%d %s %d %s %s %d/%d/%d %d/%d/%d %d %s %f %s %f\n", &vid, nme, &phn, gender, svrc, &day_st, &mon_st, &year_st, &day_ed, &mon_ed, &year_ed, &cost, type, &paid, paym, &bal) != EOF)
		{
			if (strcmp(find, nme) == 0 && find_id == vid)
			{
				chk += 1;
				tmp_res = fopen("temp_res.txt", "a");
				if (tmp_res == NULL)
				{
					printf("\nFile cannot be opened");
				}

				// Move found result to temporary file
				fprintf(tmp_res, "%d\t %s\t %d\t %s\t %s\t %d/%d/%d\t %d/%d/%d\t %d\t %s\t %.2f\t %s\t %.2f\n", vid, nme, phn, gender, svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed, cost, type, paid, paym, bal);
				// Display on console
				printf("\n\n\t\tVisit No. : %d", vid);
				printf("\n\t\t____________________________________________________________________________________\n");
				printf("\t\tName: %s   Phone: %d   Gender: %s \n", nme, phn, gender);
				printf("\t\t====================================================================================\n");
				printf("\t\t            Service needed                  Start Date              Finish Date     \n");
				printf("\t\t====================================================================================\n");
				printf("\t\t%s\t %02d/%02d/%d\t          %02d/%02d/%d\n", svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed);
				printf("\t\t____________________________________________________________________________________\n");
				printf("\t\tFee: RM %d %s   Total Paid: RM %.2f %s   Total Balance: RM %.2f\n", cost, type, paid, paym, bal);
				printf("\t\t____________________________________________________________________________________\n\n");
				fclose(tmp_res);
			}
			else if (strcmp(find, nme) == 0 && find_id != vid)
			{
				tmp_raw = fopen("temp_raw.txt", "a");
				if (tmp_raw == NULL)
				{
					printf("\nFile cannot be opened");
				}
				report = fopen("report.txt", "a");
				if (report == NULL)
				{
					printf("\nFile cannot be opened");
				}

				fprintf(tmp_raw, "%d\t %s\t %d\t %s\t %s\t %d/%d/%d\t %d/%d/%d\t %d\t %s\t %.2f\t %s\t %.2f\n", vid, nme, phn, gender, svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed, cost, type, paid, paym, bal);

				fprintf(report, "\nVisit No. : %d", vid);
				fprintf(report, "\n____________________________________________________________________________________\n");
				fprintf(report, "Name: %s   Phone: %d   Gender: %s \n", nme, phn, gender);
				fprintf(report, "====================================================================================\n");
				fprintf(report, "            Service needed                  Start Date              Finish Date     \n");
				fprintf(report, "====================================================================================\n");
				fprintf(report, "%s\t %02d/%02d/%d\t          %02d/%02d/%d\n", svrc, day_st, mon_st, year_st, day_ed, mon_ed, year_ed);
				fprintf(report, "____________________________________________________________________________________\n");
				fprintf(report, "Fee: RM %d %s   Total Paid: RM %.2f %s   Total Balance: RM %.2f\n", cost, type, paid, paym, bal);
				fprintf(report, "____________________________________________________________________________________\n\n");

				fclose(tmp_raw);
				fclose(report);
			}
		}
		fclose(raw);
		if (chk == 1)
		{
			printf("\n\t\tYay! Data Found!");
			printf("\n\t\tContinue? [1 = Yes / 0 = No]: ");
			scanf("%d", &conf);
			if (conf == 1)
			{
				system("cls");
				realtime();
				printf("\n ---------\n | Admin |\n ---------\n");
				printf("\n\t\t*** Please Insert New Data ***\n");

				tmp_res = fopen("temp_res.txt", "r");
				if (tmp_res == NULL)
				{
					printf("\nFile cannot be opened");
				}
				fscanf(tmp_res, "%d %s %d %s %s %d/%d/%d %d/%d/%d %d %s %f %s %f\n", &vid, nme, &phn, gender, svrc, &day_st, &mon_st, &year_st, &day_ed, &mon_ed, &year_ed, &cost, type, &paid, paym, &bal);
				ch.fee = cost;
				fclose(tmp_res);
				cus_pay(&ch);			// Payment information
				system("cls");
				realtime();
				printf("\n ---------\n | Admin |\n ---------\n");
				date_special(&ch);		// Get new date
				pay_update(&ch);		// Update the data
				printf("\n\n\tEnter 1 to continue, any key to Exit: ");
				scanf("%d", &opl);
				if (opl == 1)
				{
					printf("\n\tRedirecting to Admin Change Page...");
					sleep(2000);
					admin_chg();
				}
				else
				{
					exit(0);
				}

			}
			else if (conf == 0)
			{
				printf("\n\tPlease try again.");
				sleep(1000);
				printf("\n\tRedirecting to Admin Change Page...");
				sleep(2000);
				admin_chg();
				// Program will refresh the page
			}
			else
			{
				printf("\n\tError!\n\tInvalid Input!\n\tTeleporting to Admin Change Page...");
				sleep(2000);
				admin_chg();
				// Program will go to admin change page
			}
		}
		else if (chk == 0)
		{
			printf("\n\t\tOh No.. \n\t\tYour data is not here..\n\t\tLooks like you enter wrong input!\n");
			sleep(1000);
			printf("\n\n\tPlease try again.\n\tTeleporting back to Admin Change Page...");
			sleep(2000);
			admin_chg();
		}
	}
	else				// If result is 0
	{
		printf("\n\n\tInvalid Input!\n\tPlease try again.\n\tRedirecting back to Admin Change Page...");
		sleep(2000);
		admin_chg();
	}
}

// [ADMIN] Add Customer Profile
void cus_prof(struct visit* v)
{
	int i;
	system("cls");
	realtime();
	printf("\n ---------\n | Admin |\n ---------\n");
	printf("\n\n\t\tEnter Customer Information\n\t\t__________________________\n");
	printf("\n\n\t\tName (No Space): ");
	scanf("%s", &v->name);
	for (i = 0; v->name[i] != '\0'; i++)
	{
		if (v->name[i] >= 'a' && v->name[i] <= 'z')
		{
			v->name[i] = v->name[i] - 32;
		}
	}

	printf("\n\t\tPhone Number: ");
	scanf("%d", &v->num);
	printf("\n\t\tGender (M/F): ");
	scanf("%s", &v->sex);
	if (v->sex == 'm' || v->sex == 'f')
	{
		v->sex = toupper(v->sex);
	}
	else if (v->sex == 'M' || v->sex == 'F')
	{
	}
	else
	{
		printf("\n\tError! \n\tInvalid Input!");
		sleep(1000);
		admin_add();
	}
}

// [ADMIN] Add Customer Service Needed
void cus_serv(struct visit* v)
{
	int srv, feeop;

	printf("\n\t\tList of Services: ");
	printf("\n\t\t-----------------------------------------------------------------------------------------");
	printf("\n\t\t|     |                                           |             |      Service Fee      |");
	printf("\n\t\t| No  |              Service Type                 | Needed days |-----------------------|");
	printf("\n\t\t|     |                                           |             |   Normal  |   Urgent  |");
	printf("\n\t\t-----------------------------------------------------------------------------------------");
	printf("\n\t\t|  1  |      Remove virus, malware or spyware     |      2      |   30 RM   |   50 RM   |");
	printf("\n\t\t-----------------------------------------------------------------------------------------");
	printf("\n\t\t|  2  | Troubleshot and fix computer running slow |      2      |   40 RM   |   70 RM   |");
	printf("\n\t\t-----------------------------------------------------------------------------------------");
	printf("\n\t\t|  3  |         Laptop screen replacement         |      3      |  380 RM   |  430 RM   |");
	printf("\n\t\t-----------------------------------------------------------------------------------------");
	printf("\n\t\t|  4  |        Laptop keyboard replacement        |      2      |  160 RM   |  200 RM   |");
	printf("\n\t\t-----------------------------------------------------------------------------------------");
	printf("\n\t\t|  5  |        Laptop battery replacement         |      1      |  180 RM   |  210 RM   |");
	printf("\n\t\t-----------------------------------------------------------------------------------------");
	printf("\n\t\t|  6  | Operating System Format and Installation  |      2      |   50 RM   |   80 RM   |");
	printf("\n\t\t-----------------------------------------------------------------------------------------");
	printf("\n\t\t|  7  |          Data backup and recovery         |      2      |  100 RM   |  150 RM   |");
	printf("\n\t\t-----------------------------------------------------------------------------------------");
	printf("\n\t\t|  8  |       Internet connectivity issues        |      1      |   50 RM   |   75 RM   |");
	printf("\n\t\t-----------------------------------------------------------------------------------------");
	printf("\n\n\t\tSelect a service number : ");
	scanf("%d", &srv);
	if (srv < 1 || srv > 8)
	{
		printf("\n\t\t\tError!\t\t\tInvalid Input!");
		printf("\n\t\t\tPlease try again...");
		sleep(2000);
		admin_menu();
	}
	printf("\n\t\tSelect fee type [1 = Normal / 2 = Urgent]: ");
	scanf("%d", &feeop);
	if (feeop < 1 || feeop > 2)
	{
		printf("\n\tError!\n\tInvalid Input!\n");
		sleep(2000);
		admin_menu();
	}
	switch (srv)
	{
	case 1:
		v->serv = "Remove-virus,-malware-or-spyware";
		if (feeop == 1)
		{
			v->type = "NORMAL";
			v->fee = 30;
			v->days = 2;
			break;
		}
		else
		{
			v->type = "URGENT";
			v->fee = 50;
			v->days = 1;
			break;
		}
	case 2:
		v->serv = "Troubleshot-and-fix-computer-running-slow";
		if (feeop == 1)
		{
			v->type = "NORMAL";
			v->fee = 40;
			v->days = 2;
			break;
		}
		else
		{
			v->type = "URGENT";
			v->fee = 70;
			v->days = 1;
			break;
		}
	case 3:
		v->serv = "Laptop-screen-replacement";
		if (feeop == 1)
		{
			v->type = "NORMAL";
			v->fee = 380;
			v->days = 3;
			break;
		}
		else
		{
			v->type = "URGENT";
			v->fee = 430;
			v->days = 2;
			break;
		}
	case 4:
		v->serv = "Laptop-keyboard-replacement";
		if (feeop == 1)
		{
			v->type = "NORMAL";
			v->days = 2;
			v->fee = 160;
			break;
		}
		else
		{
			v->type = "URGENT";
			v->fee = 200;
			v->days = 1;
			break;
		}
	case 5:
		v->serv = "Laptop-battery-replacement";
		if (feeop == 1)
		{
			v->type = "NORMAL";
			v->days = 1;
			v->fee = 180;
			break;
		}
		else
		{
			v->type = "URGENT";
			v->fee = 210;
			v->days = 0;
			break;
		}
	case 6:
		v->serv = "Operating-System-Format-and-Installation";
		if (feeop == 1)
		{
			v->type = "NORMAL";
			v->days = 2;
			v->fee = 50;
			break;
		}
		else
		{
			v->type = "URGENT";
			v->days = 1;
			v->fee = 80;
			break;
		}
	case 7:
		v->serv = "Data-backup-and-recovery";
		if (feeop == 1)
		{
			v->type = "NORMAL";
			v->days = 2;
			v->fee = 100;
			break;
		}
		else
		{
			v->type = "URGENT";
			v->days = 1;
			v->fee = 150;
			break;
		}
	case 8:
		v->serv = "Internet-connectivity-issues";
		if (feeop == 1)
		{
			v->type = "NORMAL";
			v->days = 1;
			v->fee = 50;
			break;
		}
		else
		{
			v->type = "URGENT";
			v->days = 0;
			v->fee = 75;
			break;
		}
	default:
		printf("\n\tError!\n\tPlease try again!");
		sleep(2000);
		admin_add();
	}
}

// [ADMIN] Automatic Date function
int srvdate(struct visit* v)
{
	time_t dt = time(NULL);
	struct tm date = *localtime(&dt);
	int oddmon[7] = { 1,3,5,7,8,10,12 };
	int evenmon[4] = { 4,6,9,11 };
	int y_feb, i;

	v->dd_st = date.tm_mday;
	v->mm_st = date.tm_mon + 1;
	v->yy_st = date.tm_year + 1900;
	// For December
	if (v->mm_st == 12)
	{
		if (v->dd_st == 31 && v->days > 0)
		{
			v->dd_ed = (v->dd_st + v->days) - 31;
			v->yy_ed = v->yy_st + 1;
			v->mm_ed = 1;
		}
		else
		{
			v->dd_ed = v->dd_st + v->days;
			v->mm_ed = v->mm_st;
			v->yy_ed = v->yy_st;
		}
	}
	// For February
	else if (v->mm_st == 2)
	{
		do
		{
			y_feb = v->yy_st - 4;
		} while (y_feb > 0);

		if (y_feb == 0)		// 29 days for every 4 years
		{
			if (v->dd_st == 29 && v->days > 0)
			{
				v->dd_ed = (v->dd_st + v->days) - 29;
				v->mm_ed = v->mm_st + 1;
				v->yy_ed = v->yy_st;
			}
			else
			{
				v->dd_ed = v->dd_st + v->days;
				v->mm_ed = v->mm_st;
				v->yy_ed = v->yy_st;
			}
		}
		else				// 28 days for the rest
		{
			if (v->dd_st == 28 && v->days > 0)
			{
				v->dd_ed = (v->dd_st + v->days) - 28;
				v->mm_ed = v->mm_st + 1;
				v->yy_ed = v->yy_st;
			}
			else
			{
				v->dd_ed = v->dd_st + v->days;
				v->mm_ed = v->mm_st;
				v->yy_ed = v->yy_st;
			}
		}
	}
	// Other months
	else
	{
		for (i = 0; i <= 7; i++)
		{
			if (v->mm_st == oddmon[i])			// For months with 31 days
			{
				if (v->dd_st == 31 && v->days > 0)
				{
					v->dd_ed = (v->dd_st + v->days) - 31;
					v->mm_ed = v->mm_st + 1;
					v->yy_ed = v->yy_st;
				}
				else
				{
					v->dd_ed = v->dd_st + v->days;
					v->mm_ed = v->mm_st;
					v->yy_ed = v->yy_st;
				}
			}
			else if (v->mm_st == evenmon[i])	// For months with 30 days
			{
				if (v->dd_st == 30 && v->days > 0)
				{
					v->dd_ed = (v->dd_st + v->days) - 30;
					v->mm_ed = v->mm_st + 1;
					v->yy_ed = v->yy_st;
				}
				else
				{
					v->dd_ed = v->dd_st + v->days;
					v->mm_ed = v->mm_st;
					v->yy_ed = v->yy_st;
				}
			}
		}
	}
	return 0;
}

// [ADMIN] Add Customer Payment
void cus_pay(struct visit* v)
{
	int pm;

	printf("\n\t\tEnter payment information: ");
	printf("\n\t\t__________________________");
	printf("\n\n\t\tPayment method: \n\t\t1. Debit/Credit \n\t\t2. Cash");
	printf("\n\n\t\t__________________");
	printf("\n\t\tEnter option: ");
	scanf("%d", &pm);
	if (pm == 1)
	{
		v->paym = ("Debit/Credit");
	}
	else if (pm == 2)
	{
		v->paym = ("Cash");
	}
	else
	{
		printf("\n\n\t\t\tError! Wrong Input!");
		sleep(1000);
		admin_add();
	}

	printf("\n\t\tEnter amount paid (NUMBERS ONLY): RM  ");
	scanf("%f", &v->paid);
	v->balnc = v->paid - v->fee;
}

// [ADMIN] Generate visit ID
void visit_id(struct visit* v)
{

	FILE* temp_id, * id;
	int no, pass;

	id = fopen("ID.txt", "r");
	if (id == NULL)
	{
		printf("\nFile cannot be opened");
	}
	fscanf(id, "%d", &no);
	pass = no;
	v->id = no;
	fclose(id);

	temp_id = fopen("temp_id.txt", "w");
	if (temp_id == NULL)
	{
		printf("\nFile cannot be opened");
	}
	pass += 1;
	fprintf(temp_id, "%d", pass);
	fclose(temp_id);
	remove("ID.txt");
	rename("temp_id.txt", "ID.txt");
}

// [ADMIN] Write Visit Information to File
int write(struct visit* v)
{
	FILE* report, * raw;
	report = fopen("report.txt", "a");
	if (report == NULL)
	{
		printf("\nFile cannot be opened");
	}

	raw = fopen("rawdata.txt", "a");
	if (raw == NULL)
	{
		printf("\nFile cannot be opened");
	}

	// Write the data to system read
	fprintf(raw, "%d\t %s\t %d\t %c\t %s\t %02d/%02d/%d\t %02d/%02d/%d\t %d(%s)\t %.2f(%s)\t %.2f\n", v->id, v->name, v->num, v->sex, v->serv, v->dd_st, v->mm_st, v->yy_st, v->dd_ed, v->mm_ed, v->yy_ed, v->fee, v->type, v->paid, v->paym, v->balnc);

	// Write the data to display
	fprintf(report, "\nVisit No. : %d", v->id);
	fprintf(report, "\n____________________________________________________________________________________\n");
	fprintf(report, "Name: %s   Phone: %d   Gender: %c \n", v->name, v->num, v->sex);
	fprintf(report, "====================================================================================\n");
	fprintf(report, "            Service needed                  Start Date              Finish Date     \n");
	fprintf(report, "====================================================================================\n");
	fprintf(report, "%s\t %02d/%02d/%d\t          %02d/%02d/%d\n", v->serv, v->dd_st, v->mm_st, v->yy_st, v->dd_ed, v->mm_ed, v->yy_ed);
	fprintf(report, "____________________________________________________________________________________\n");
	fprintf(report, "Fee: RM %d [%s]   Total Paid: RM %.2f [%s]   Total Balance: RM %.2f\n", v->fee, v->type, v->paid, v->paym, v->balnc);
	fprintf(report, "____________________________________________________________________________________\n\n");

	fclose(report);
	fclose(raw);
	return 0;
}