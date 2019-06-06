while (ile_mikrosekund>=1000000)
{
	usleep(999999);
	ile_mikrosekund-=1000000;
}
usleep(ile_mikrosekund);