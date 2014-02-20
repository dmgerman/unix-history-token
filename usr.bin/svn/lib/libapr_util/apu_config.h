begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* include/private/apu_config.h.  Generated from apu_config.h.in by configure.  */
end_comment

begin_comment
comment|/* include/private/apu_config.h.in.  Generated from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* Define if the system crypt() function is threadsafe */
end_comment

begin_comment
comment|/* #undef APU_CRYPT_THREADSAFE */
end_comment

begin_comment
comment|/* Define to 1 if modular components are built as DSOs */
end_comment

begin_comment
comment|/* #undef APU_DSO_BUILD */
end_comment

begin_comment
comment|/* Define to be absolute path to DSO directory */
end_comment

begin_comment
comment|/* #undef APU_DSO_LIBDIR */
end_comment

begin_comment
comment|/* Define if the inbuf parm to iconv() is const char ** */
end_comment

begin_define
define|#
directive|define
name|APU_ICONV_INBUF_CONST
value|1
end_define

begin_comment
comment|/* Define that OpenSSL uses const buffers */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_OPENSSL_CONST_BUFFERS
value|1
end_define

begin_comment
comment|/* Define if crypt_r has uses CRYPTD */
end_comment

begin_comment
comment|/* #undef CRYPT_R_CRYPTD */
end_comment

begin_comment
comment|/* Define if crypt_r uses struct crypt_data */
end_comment

begin_comment
comment|/* #undef CRYPT_R_STRUCT_CRYPT_DATA */
end_comment

begin_comment
comment|/* Define if CODESET is defined in langinfo.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_CODESET
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `crypt_r' function. */
end_comment

begin_comment
comment|/* #undef HAVE_CRYPT_R */
end_comment

begin_comment
comment|/* Define to 1 if you have the declaration of `EVP_PKEY_CTX_new', and to 0 if    you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_EVP_PKEY_CTX_NEW
value|1
end_define

begin_comment
comment|/* Define if expat.h is available */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXPAT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<freetds/sybdb.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_FREETDS_SYBDB_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<iconv.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_ICONV_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<inttypes.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<langinfo.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LANGINFO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<lber.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LBER_H */
end_comment

begin_comment
comment|/* Defined if ldap.h is present */
end_comment

begin_comment
comment|/* #undef HAVE_LDAP_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<ldap_ssl.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LDAP_SSL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<libpq-fe.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LIBPQ_FE_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<memory.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<mysql.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MYSQL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<mysql/mysql.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MYSQL_MYSQL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<mysql/my_global.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MYSQL_MY_GLOBAL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<mysql/my_sys.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MYSQL_MY_SYS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<my_global.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MY_GLOBAL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<my_sys.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MY_SYS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `nl_langinfo' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NL_LANGINFO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<nss.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NSS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<nss/nss.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NSS_NSS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<nss/pk11pub.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NSS_PK11PUB_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<oci.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_OCI_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<odbc/sql.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_ODBC_SQL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<openssl/x509.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENSSL_X509_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<pk11pub.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_PK11PUB_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<postgresql/libpq-fe.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_POSTGRESQL_LIBPQ_FE_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<prerror.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_PRERROR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sqlite3.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SQLITE3_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sqlite.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SQLITE_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sql.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SQL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<stdint.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<strings.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<string.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sybdb.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYBDB_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/stat.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<unistd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define if xmlparse/xmlparse.h is available */
end_comment

begin_comment
comment|/* #undef HAVE_XMLPARSE_XMLPARSE_H */
end_comment

begin_comment
comment|/* Define if xmltok/xmlparse.h is available */
end_comment

begin_comment
comment|/* #undef HAVE_XMLTOK_XMLPARSE_H */
end_comment

begin_comment
comment|/* Define if xml/xmlparse.h is available */
end_comment

begin_comment
comment|/* #undef HAVE_XML_XMLPARSE_H */
end_comment

begin_comment
comment|/* Define if ldap_set_rebind_proc takes three arguments */
end_comment

begin_comment
comment|/* #undef LDAP_SET_REBIND_PROC_THREE */
end_comment

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|""
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|""
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|""
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|""
end_define

begin_comment
comment|/* Define to the home page for this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_URL
value|""
end_define

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|""
end_define

begin_comment
comment|/* Define to 1 if you have the ANSI C header files. */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

end_unit

