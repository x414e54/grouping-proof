# $Id: Makefile.am 576 2010-09-04 10:47:07Z rtartiere@il4p.fr $

AM_CFLAGS = -I. -I$(top_srcdir)/libfreefare @LIBNFC_CFLAGS@
AM_LDFLAGS = @LIBNFC_LIBS@

bin_PROGRAMS = mifare-classic-format \
	       mifare-classic-write-ndef \
	       mifare-desfire-access \
	       mifare-desfire-format \
	       mifare-desfire-info \
	       mifare-desfire-write-ndef

mifare_classic_format_SOURCES = mifare-classic-format.c
mifare_classic_format_LDADD = -lnfc $(top_builddir)/libfreefare/libfreefare.la

mifare_classic_write_ndef_SOURCES = mifare-classic-write-ndef.c
mifare_classic_write_ndef_LDADD = -lnfc $(top_builddir)/libfreefare/libfreefare.la

mifare_desfire_access_SOURCES = mifare-desfire-access.c
mifare_desfire_access_LDADD = -lnfc $(top_builddir)/libfreefare/libfreefare.la

mifare_desfire_format_SOURCES = mifare-desfire-format.c
mifare_desfire_format_LDADD = -lnfc $(top_builddir)/libfreefare/libfreefare.la

mifare_desfire_info_SOURCES = mifare-desfire-info.c
mifare_desfire_info_LDADD = -lnfc $(top_builddir)/libfreefare/libfreefare.la -lm

mifare_desfire_write_ndef_SOURCES = mifare-desfire-write-ndef.c
mifare_desfire_write_ndef_LDADD = -lnfc $(top_builddir)/libfreefare/libfreefare.la

CLEANFILES=	*.gcno
