#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void main()
{
	unsigned int c,d,r1,r2;
	int a,b;
	char ip[50],subnet[50],*h[50],*j[50];
	struct in_addr y,z,p1,p2;
	
	printf("\nEnter the IP Address: ");
	scanf("%s",ip);
	printf("\nEnter the Subnet Mask: ");
	scanf("%s",subnet);
	
	a=inet_aton(ip,&y);
	b=inet_aton(subnet,&z);
	c=ntohl(y.s_addr);
	d=ntohl(z.s_addr);
	
	if(a!=0 && b!=0)
	{
		printf("\nValid");
		
		r1=c&d;
		p1.s_addr=htonl(r1);
		h[0]=inet_ntoa(p1);
		printf("\nNetwork ID = %s",h[0]);
		
		r2=c&(~d);
		p2.s_addr=htonl(r2);
		j[0]=inet_ntoa(p2);
		printf("\nHOST ID = %s\n",j[0]);
	}
	else 
		printf("\nInvalid");
}
