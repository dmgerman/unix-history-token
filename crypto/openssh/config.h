begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h.  Generated from config.h.in by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated from configure.ac by autoheader.  */
end_comment

begin_comment
comment|/* Define if building universal (internal helper macro) */
end_comment

begin_comment
comment|/* #undef AC_APPLE_UNIVERSAL_BUILD */
end_comment

begin_comment
comment|/* Define if you have a getaddrinfo that fails for the all-zeros IPv6 address    */
end_comment

begin_comment
comment|/* #undef AIX_GETNAMEINFO_HACK */
end_comment

begin_comment
comment|/* Define if your AIX loginfailed() function takes 4 arguments (AIX>= 5.2) */
end_comment

begin_comment
comment|/* #undef AIX_LOGINFAILED_4ARG */
end_comment

begin_comment
comment|/* System only supports IPv4 audit records */
end_comment

begin_comment
comment|/* #undef AU_IPv4 */
end_comment

begin_comment
comment|/* Define if your resolver libs need this for getrrsetbyname */
end_comment

begin_comment
comment|/* #undef BIND_8_COMPAT */
end_comment

begin_comment
comment|/* The system has incomplete BSM API */
end_comment

begin_comment
comment|/* #undef BROKEN_BSM_API */
end_comment

begin_comment
comment|/* Define if cmsg_type is not passed correctly */
end_comment

begin_comment
comment|/* #undef BROKEN_CMSG_TYPE */
end_comment

begin_comment
comment|/* getaddrinfo is broken (if present) */
end_comment

begin_comment
comment|/* #undef BROKEN_GETADDRINFO */
end_comment

begin_comment
comment|/* getgroups(0,NULL) will return -1 */
end_comment

begin_comment
comment|/* #undef BROKEN_GETGROUPS */
end_comment

begin_comment
comment|/* FreeBSD glob does not do what we need */
end_comment

begin_define
define|#
directive|define
name|BROKEN_GLOB
value|1
end_define

begin_comment
comment|/* Define if you system's inet_ntoa is busted (e.g. Irix gcc issue) */
end_comment

begin_comment
comment|/* #undef BROKEN_INET_NTOA */
end_comment

begin_comment
comment|/* ia_uinfo routines not supported by OS yet */
end_comment

begin_comment
comment|/* #undef BROKEN_LIBIAF */
end_comment

begin_comment
comment|/* Define if your struct dirent expects you to allocate extra space for d_name    */
end_comment

begin_comment
comment|/* #undef BROKEN_ONE_BYTE_DIRENT_D_NAME */
end_comment

begin_comment
comment|/* Can't do comparisons on readv */
end_comment

begin_comment
comment|/* #undef BROKEN_READV_COMPARISON */
end_comment

begin_comment
comment|/* NetBSD read function is sometimes redirected, breaking atomicio comparisons    against it */
end_comment

begin_comment
comment|/* #undef BROKEN_READ_COMPARISON */
end_comment

begin_comment
comment|/* realpath does not work with nonexistent files */
end_comment

begin_define
define|#
directive|define
name|BROKEN_REALPATH
value|1
end_define

begin_comment
comment|/* Needed for NeXT */
end_comment

begin_comment
comment|/* #undef BROKEN_SAVED_UIDS */
end_comment

begin_comment
comment|/* Define if your setregid() is broken */
end_comment

begin_comment
comment|/* #undef BROKEN_SETREGID */
end_comment

begin_comment
comment|/* Define if your setresgid() is broken */
end_comment

begin_comment
comment|/* #undef BROKEN_SETRESGID */
end_comment

begin_comment
comment|/* Define if your setresuid() is broken */
end_comment

begin_comment
comment|/* #undef BROKEN_SETRESUID */
end_comment

begin_comment
comment|/* Define if your setreuid() is broken */
end_comment

begin_comment
comment|/* #undef BROKEN_SETREUID */
end_comment

begin_comment
comment|/* LynxOS has broken setvbuf() implementation */
end_comment

begin_comment
comment|/* #undef BROKEN_SETVBUF */
end_comment

begin_comment
comment|/* QNX shadow support is broken */
end_comment

begin_comment
comment|/* #undef BROKEN_SHADOW_EXPIRE */
end_comment

begin_comment
comment|/* Define if your snprintf is busted */
end_comment

begin_comment
comment|/* #undef BROKEN_SNPRINTF */
end_comment

begin_comment
comment|/* strnvis detected broken */
end_comment

begin_define
define|#
directive|define
name|BROKEN_STRNVIS
value|1
end_define

begin_comment
comment|/* tcgetattr with ICANON may hang */
end_comment

begin_comment
comment|/* #undef BROKEN_TCGETATTR_ICANON */
end_comment

begin_comment
comment|/* updwtmpx is broken (if present) */
end_comment

begin_comment
comment|/* #undef BROKEN_UPDWTMPX */
end_comment

begin_comment
comment|/* Define if you have BSD auth support */
end_comment

begin_comment
comment|/* #undef BSD_AUTH */
end_comment

begin_comment
comment|/* Define if you want to specify the path to your lastlog file */
end_comment

begin_comment
comment|/* #undef CONF_LASTLOG_FILE */
end_comment

begin_comment
comment|/* Define if you want to specify the path to your utmp file */
end_comment

begin_comment
comment|/* #undef CONF_UTMP_FILE */
end_comment

begin_comment
comment|/* Define if you want to specify the path to your wtmpx file */
end_comment

begin_comment
comment|/* #undef CONF_WTMPX_FILE */
end_comment

begin_comment
comment|/* Define if you want to specify the path to your wtmp file */
end_comment

begin_comment
comment|/* #undef CONF_WTMP_FILE */
end_comment

begin_comment
comment|/* Define if your platform needs to skip post auth file descriptor passing */
end_comment

begin_comment
comment|/* #undef DISABLE_FD_PASSING */
end_comment

begin_comment
comment|/* Define if you don't want to use lastlog */
end_comment

begin_define
define|#
directive|define
name|DISABLE_LASTLOG
value|1
end_define

begin_comment
comment|/* Define if you don't want to use your system's login() call */
end_comment

begin_comment
comment|/* #undef DISABLE_LOGIN */
end_comment

begin_comment
comment|/* Define if you don't want to use pututline() etc. to write [uw]tmp */
end_comment

begin_comment
comment|/* #undef DISABLE_PUTUTLINE */
end_comment

begin_comment
comment|/* Define if you don't want to use pututxline() etc. to write [uw]tmpx */
end_comment

begin_comment
comment|/* #undef DISABLE_PUTUTXLINE */
end_comment

begin_comment
comment|/* Define if you want to disable shadow passwords */
end_comment

begin_comment
comment|/* #undef DISABLE_SHADOW */
end_comment

begin_comment
comment|/* Define if you don't want to use utmp */
end_comment

begin_define
define|#
directive|define
name|DISABLE_UTMP
value|1
end_define

begin_comment
comment|/* Define if you don't want to use utmpx */
end_comment

begin_comment
comment|/* #undef DISABLE_UTMPX */
end_comment

begin_comment
comment|/* Define if you don't want to use wtmp */
end_comment

begin_define
define|#
directive|define
name|DISABLE_WTMP
value|1
end_define

begin_comment
comment|/* Define if you don't want to use wtmpx */
end_comment

begin_define
define|#
directive|define
name|DISABLE_WTMPX
value|1
end_define

begin_comment
comment|/* Enable for PKCS#11 support */
end_comment

begin_define
define|#
directive|define
name|ENABLE_PKCS11
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* File names may not contain backslash characters */
end_comment

begin_comment
comment|/* #undef FILESYSTEM_NO_BACKSLASH */
end_comment

begin_comment
comment|/* fsid_t has member val */
end_comment

begin_comment
comment|/* #undef FSID_HAS_VAL */
end_comment

begin_comment
comment|/* fsid_t has member __val */
end_comment

begin_comment
comment|/* #undef FSID_HAS___VAL */
end_comment

begin_comment
comment|/* Define to 1 if the `getpgrp' function requires zero arguments. */
end_comment

begin_define
define|#
directive|define
name|GETPGRP_VOID
value|1
end_define

begin_comment
comment|/* Conflicting defs for getspnam */
end_comment

begin_comment
comment|/* #undef GETSPNAM_CONFLICTING_DEFS */
end_comment

begin_comment
comment|/* Define if your system glob() function has the GLOB_ALTDIRFUNC extension */
end_comment

begin_define
define|#
directive|define
name|GLOB_HAS_ALTDIRFUNC
value|1
end_define

begin_comment
comment|/* Define if your system glob() function has gl_matchc options in glob_t */
end_comment

begin_define
define|#
directive|define
name|GLOB_HAS_GL_MATCHC
value|1
end_define

begin_comment
comment|/* Define if your system glob() function has gl_statv options in glob_t */
end_comment

begin_comment
comment|/* #undef GLOB_HAS_GL_STATV */
end_comment

begin_comment
comment|/* Define this if you want GSSAPI support in the version 2 protocol */
end_comment

begin_comment
comment|/* #undef GSSAPI */
end_comment

begin_comment
comment|/* Define if you want to use shadow password expire field */
end_comment

begin_comment
comment|/* #undef HAS_SHADOW_EXPIRE */
end_comment

begin_comment
comment|/* Define if your system uses access rights style file descriptor passing */
end_comment

begin_comment
comment|/* #undef HAVE_ACCRIGHTS_IN_MSGHDR */
end_comment

begin_comment
comment|/* Define if you have ut_addr in utmp.h */
end_comment

begin_comment
comment|/* #undef HAVE_ADDR_IN_UTMP */
end_comment

begin_comment
comment|/* Define if you have ut_addr in utmpx.h */
end_comment

begin_comment
comment|/* #undef HAVE_ADDR_IN_UTMPX */
end_comment

begin_comment
comment|/* Define if you have ut_addr_v6 in utmp.h */
end_comment

begin_comment
comment|/* #undef HAVE_ADDR_V6_IN_UTMP */
end_comment

begin_comment
comment|/* Define if you have ut_addr_v6 in utmpx.h */
end_comment

begin_comment
comment|/* #undef HAVE_ADDR_V6_IN_UTMPX */
end_comment

begin_comment
comment|/* Define to 1 if you have the `arc4random' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARC4RANDOM
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `arc4random_buf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARC4RANDOM_BUF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `arc4random_stir' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARC4RANDOM_STIR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `arc4random_uniform' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARC4RANDOM_UNIFORM
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `asprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ASPRINTF
value|1
end_define

begin_comment
comment|/* OpenBSD's gcc has bounded */
end_comment

begin_comment
comment|/* #undef HAVE_ATTRIBUTE__BOUNDED__ */
end_comment

begin_comment
comment|/* Have attribute nonnull */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATTRIBUTE__NONNULL__
value|1
end_define

begin_comment
comment|/* OpenBSD's gcc has sentinel */
end_comment

begin_comment
comment|/* #undef HAVE_ATTRIBUTE__SENTINEL__ */
end_comment

begin_comment
comment|/* Define to 1 if you have the `aug_get_machine' function. */
end_comment

begin_comment
comment|/* #undef HAVE_AUG_GET_MACHINE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `b64_ntop' function. */
end_comment

begin_comment
comment|/* #undef HAVE_B64_NTOP */
end_comment

begin_comment
comment|/* Define to 1 if you have the `b64_pton' function. */
end_comment

begin_comment
comment|/* #undef HAVE_B64_PTON */
end_comment

begin_comment
comment|/* Define if you have the basename function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_BASENAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `bcopy' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_BCOPY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `bcrypt_pbkdf' function. */
end_comment

begin_comment
comment|/* #undef HAVE_BCRYPT_PBKDF */
end_comment

begin_comment
comment|/* Define to 1 if you have the `bindresvport_sa' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_BINDRESVPORT_SA
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `blf_enc' function. */
end_comment

begin_comment
comment|/* #undef HAVE_BLF_ENC */
end_comment

begin_comment
comment|/* Define to 1 if you have the<blf.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_BLF_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `Blowfish_expand0state' function. */
end_comment

begin_comment
comment|/* #undef HAVE_BLOWFISH_EXPAND0STATE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `Blowfish_expandstate' function. */
end_comment

begin_comment
comment|/* #undef HAVE_BLOWFISH_EXPANDSTATE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `Blowfish_initstate' function. */
end_comment

begin_comment
comment|/* #undef HAVE_BLOWFISH_INITSTATE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `Blowfish_stream2word' function. */
end_comment

begin_comment
comment|/* #undef HAVE_BLOWFISH_STREAM2WORD */
end_comment

begin_comment
comment|/* Define to 1 if you have the `BN_is_prime_ex' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_BN_IS_PRIME_EX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<bsd/libutil.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_BSD_LIBUTIL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<bsm/audit.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_BSM_AUDIT_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<bstring.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_BSTRING_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `cap_rights_limit' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CAP_RIGHTS_LIMIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `clock' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOCK
value|1
end_define

begin_comment
comment|/* Have clock_gettime */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOCK_GETTIME
value|1
end_define

begin_comment
comment|/* define if you have clock_t data type */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOCK_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `closefrom' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOSEFROM
value|1
end_define

begin_comment
comment|/* Define if gai_strerror() returns const char * */
end_comment

begin_define
define|#
directive|define
name|HAVE_CONST_GAI_STRERROR_PROTO
value|1
end_define

begin_comment
comment|/* Define if your system uses ancillary data style file descriptor passing */
end_comment

begin_define
define|#
directive|define
name|HAVE_CONTROL_IN_MSGHDR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `crypt' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CRYPT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<crypto/sha2.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_CRYPTO_SHA2_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<crypt.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_CRYPT_H */
end_comment

begin_comment
comment|/* Define if you are on Cygwin */
end_comment

begin_comment
comment|/* #undef HAVE_CYGWIN */
end_comment

begin_comment
comment|/* Define if your libraries define daemon() */
end_comment

begin_define
define|#
directive|define
name|HAVE_DAEMON
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `AI_NUMERICSERV', and to 0 if    you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_AI_NUMERICSERV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `authenticate', and to 0 if you    don't. */
end_comment

begin_comment
comment|/* #undef HAVE_DECL_AUTHENTICATE */
end_comment

begin_comment
comment|/* Define to 1 if you have the declaration of `GLOB_NOMATCH', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_GLOB_NOMATCH
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `GSS_C_NT_HOSTBASED_SERVICE',    and to 0 if you don't. */
end_comment

begin_comment
comment|/* #undef HAVE_DECL_GSS_C_NT_HOSTBASED_SERVICE */
end_comment

begin_comment
comment|/* Define to 1 if you have the declaration of `howmany', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_HOWMANY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `h_errno', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_H_ERRNO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `loginfailed', and to 0 if you    don't. */
end_comment

begin_comment
comment|/* #undef HAVE_DECL_LOGINFAILED */
end_comment

begin_comment
comment|/* Define to 1 if you have the declaration of `loginrestrictions', and to 0 if    you don't. */
end_comment

begin_comment
comment|/* #undef HAVE_DECL_LOGINRESTRICTIONS */
end_comment

begin_comment
comment|/* Define to 1 if you have the declaration of `loginsuccess', and to 0 if you    don't. */
end_comment

begin_comment
comment|/* #undef HAVE_DECL_LOGINSUCCESS */
end_comment

begin_comment
comment|/* Define to 1 if you have the declaration of `MAXSYMLINKS', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_MAXSYMLINKS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `NFDBITS', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_NFDBITS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `offsetof', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_OFFSETOF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `O_NONBLOCK', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_O_NONBLOCK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `passwdexpired', and to 0 if you    don't. */
end_comment

begin_comment
comment|/* #undef HAVE_DECL_PASSWDEXPIRED */
end_comment

begin_comment
comment|/* Define to 1 if you have the declaration of `setauthdb', and to 0 if you    don't. */
end_comment

begin_comment
comment|/* #undef HAVE_DECL_SETAUTHDB */
end_comment

begin_comment
comment|/* Define to 1 if you have the declaration of `SHUT_RD', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_SHUT_RD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `writev', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_WRITEV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `_getlong', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL__GETLONG
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `_getshort', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL__GETSHORT
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the `DES_crypt' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DES_CRYPT
value|1
end_define

begin_comment
comment|/* Define if you have /dev/ptmx */
end_comment

begin_comment
comment|/* #undef HAVE_DEV_PTMX */
end_comment

begin_comment
comment|/* Define if you have /dev/ptc */
end_comment

begin_comment
comment|/* #undef HAVE_DEV_PTS_AND_PTC */
end_comment

begin_comment
comment|/* Define to 1 if you have the<dirent.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `dirfd' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRFD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `dirname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRNAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `DSA_generate_parameters_ex' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DSA_GENERATE_PARAMETERS_EX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<elf.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ELF_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `endgrent' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ENDGRENT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<endian.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_ENDIAN_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `endutent' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ENDUTENT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `endutxent' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ENDUTXENT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `err' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `errx' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<err.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERR_H
value|1
end_define

begin_comment
comment|/* Define if your system has /etc/default/login */
end_comment

begin_comment
comment|/* #undef HAVE_ETC_DEFAULT_LOGIN */
end_comment

begin_comment
comment|/* Define if libcrypto has EVP_CIPHER_CTX_ctrl */
end_comment

begin_define
define|#
directive|define
name|HAVE_EVP_CIPHER_CTX_CTRL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `EVP_DigestFinal_ex' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_EVP_DIGESTFINAL_EX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `EVP_DigestInit_ex' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_EVP_DIGESTINIT_EX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `EVP_MD_CTX_cleanup' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_EVP_MD_CTX_CLEANUP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `EVP_MD_CTX_copy_ex' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_EVP_MD_CTX_COPY_EX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `EVP_MD_CTX_init' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_EVP_MD_CTX_INIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `EVP_ripemd160' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_EVP_RIPEMD160
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `EVP_sha256' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_EVP_SHA256
value|1
end_define

begin_comment
comment|/* Define if you have ut_exit in utmp.h */
end_comment

begin_comment
comment|/* #undef HAVE_EXIT_IN_UTMP */
end_comment

begin_comment
comment|/* Define to 1 if you have the `explicit_bzero' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXPLICIT_BZERO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fchmod' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCHMOD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fchown' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCHOWN
value|1
end_define

begin_comment
comment|/* Use F_CLOSEM fcntl for closefrom */
end_comment

begin_comment
comment|/* #undef HAVE_FCNTL_CLOSEM */
end_comment

begin_comment
comment|/* Define to 1 if you have the<fcntl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `fd_mask'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FD_MASK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<features.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_FEATURES_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<floatingpoint.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FLOATINGPOINT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fmt_scaled' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FMT_SCALED */
end_comment

begin_comment
comment|/* Define to 1 if you have the `freeaddrinfo' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FREEADDRINFO
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `fsblkcnt_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FSBLKCNT_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `fsfilcnt_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FSFILCNT_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fstatfs' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FSTATFS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fstatvfs' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FSTATVFS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `futimes' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FUTIMES
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `gai_strerror' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GAI_STRERROR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getaddrinfo' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETADDRINFO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getaudit' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETAUDIT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getaudit_addr' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETAUDIT_ADDR */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getcwd' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCWD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getgrouplist' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGROUPLIST
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getgrset' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETGRSET */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getlastlogxbyname' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETLASTLOGXBYNAME */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getluid' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETLUID */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getnameinfo' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETNAMEINFO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getopt' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETOPT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<getopt.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETOPT_H
value|1
end_define

begin_comment
comment|/* Define if your getopt(3) defines and uses optreset */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETOPT_OPTRESET
value|1
end_define

begin_comment
comment|/* Define if your libraries define getpagesize() */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPAGESIZE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpeereid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPEEREID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpeerucred' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETPEERUCRED */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getpgid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPGID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpgrp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPGRP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpwanam' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETPWANAM */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getrlimit' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETRLIMIT
value|1
end_define

begin_comment
comment|/* Define if getrrsetbyname() exists */
end_comment

begin_comment
comment|/* #undef HAVE_GETRRSETBYNAME */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getrusage' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETRUSAGE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getseuserbyname' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETSEUSERBYNAME */
end_comment

begin_comment
comment|/* Define to 1 if you have the `gettimeofday' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getttyent' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETTTYENT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getutent' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETUTENT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getutid' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETUTID */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getutline' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETUTLINE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getutxent' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUTXENT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getutxid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUTXID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getutxline' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUTXLINE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getutxuser' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUTXUSER
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `get_default_context_with_level' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GET_DEFAULT_CONTEXT_WITH_LEVEL */
end_comment

begin_comment
comment|/* Define to 1 if you have the `glob' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GLOB
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<glob.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GLOB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `group_from_gid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GROUP_FROM_GID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<gssapi_generic.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_GSSAPI_GENERIC_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<gssapi/gssapi_generic.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_GSSAPI_GSSAPI_GENERIC_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<gssapi/gssapi.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_GSSAPI_GSSAPI_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<gssapi/gssapi_krb5.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_GSSAPI_GSSAPI_KRB5_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<gssapi.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_GSSAPI_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<gssapi_krb5.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_GSSAPI_KRB5_H */
end_comment

begin_comment
comment|/* Define if HEADER.ad exists in arpa/nameser.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_HEADER_AD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `HMAC_CTX_init' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_HMAC_CTX_INIT
value|1
end_define

begin_comment
comment|/* Define if you have ut_host in utmp.h */
end_comment

begin_comment
comment|/* #undef HAVE_HOST_IN_UTMP */
end_comment

begin_comment
comment|/* Define if you have ut_host in utmpx.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_HOST_IN_UTMPX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<iaf.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_IAF_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<ia.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_IA_H */
end_comment

begin_comment
comment|/* Define if you have ut_id in utmp.h */
end_comment

begin_comment
comment|/* #undef HAVE_ID_IN_UTMP */
end_comment

begin_comment
comment|/* Define if you have ut_id in utmpx.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_ID_IN_UTMPX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `inet_aton' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_ATON
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `inet_ntoa' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_NTOA
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `inet_ntop' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_NTOP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `innetgr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INNETGR
value|1
end_define

begin_comment
comment|/* define if you have int64_t data type */
end_comment

begin_define
define|#
directive|define
name|HAVE_INT64_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `intmax_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTMAX_T
value|1
end_define

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
comment|/* define if you have intxx_t data type */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTXX_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `in_addr_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_IN_ADDR_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `in_port_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_IN_PORT_T
value|1
end_define

begin_comment
comment|/* Define if you have isblank(3C). */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISBLANK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `krb5_cc_new_unique' function. */
end_comment

begin_comment
comment|/* #undef HAVE_KRB5_CC_NEW_UNIQUE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `krb5_free_error_message' function. */
end_comment

begin_comment
comment|/* #undef HAVE_KRB5_FREE_ERROR_MESSAGE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `krb5_get_error_message' function. */
end_comment

begin_comment
comment|/* #undef HAVE_KRB5_GET_ERROR_MESSAGE */
end_comment

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
comment|/* Define to 1 if you have the<lastlog.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LASTLOG_H */
end_comment

begin_comment
comment|/* Define if you want ldns support */
end_comment

begin_comment
comment|/* #undef HAVE_LDNS */
end_comment

begin_comment
comment|/* Define to 1 if you have the<libaudit.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LIBAUDIT_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `bsm' library (-lbsm). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBBSM */
end_comment

begin_comment
comment|/* Define to 1 if you have the `crypt' library (-lcrypt). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBCRYPT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `dl' library (-ldl). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBDL */
end_comment

begin_comment
comment|/* Define to 1 if you have the<libgen.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBGEN_H
value|1
end_define

begin_comment
comment|/* Define if system has libiaf that supports set_id */
end_comment

begin_comment
comment|/* #undef HAVE_LIBIAF */
end_comment

begin_comment
comment|/* Define to 1 if you have the `network' library (-lnetwork). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBNETWORK */
end_comment

begin_comment
comment|/* Define to 1 if you have the `pam' library (-lpam). */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBPAM
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `socket' library (-lsocket). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSOCKET */
end_comment

begin_comment
comment|/* Define to 1 if you have the<libutil.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBUTIL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `xnet' library (-lxnet). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBXNET */
end_comment

begin_comment
comment|/* Define to 1 if you have the `z' library (-lz). */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBZ
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<limits.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<linux/audit.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_AUDIT_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<linux/filter.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_FILTER_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<linux/if_tun.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_IF_TUN_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<linux/seccomp.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_SECCOMP_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `llabs' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LLABS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<locale.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCALE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `login' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LOGIN */
end_comment

begin_comment
comment|/* Define to 1 if you have the<login_cap.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOGIN_CAP_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `login_getcapbool' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOGIN_GETCAPBOOL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<login.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LOGIN_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `logout' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LOGOUT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `logwtmp' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LOGWTMP */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `long double'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_DOUBLE
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `long long'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_LONG
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<maillock.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MAILLOCK_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `mblen' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MBLEN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mbtowc' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MBTOWC
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `md5_crypt' function. */
end_comment

begin_comment
comment|/* #undef HAVE_MD5_CRYPT */
end_comment

begin_comment
comment|/* Define if you want to allow MD5 passwords */
end_comment

begin_comment
comment|/* #undef HAVE_MD5_PASSWORDS */
end_comment

begin_comment
comment|/* Define to 1 if you have the `memmove' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
value|1
end_define

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
comment|/* Define to 1 if you have the `memset_s' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMSET_S
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mkdtemp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKDTEMP
value|1
end_define

begin_comment
comment|/* define if you have mode_t data type */
end_comment

begin_define
define|#
directive|define
name|HAVE_MODE_T
value|1
end_define

begin_comment
comment|/* Some systems put nanosleep outside of libc */
end_comment

begin_define
define|#
directive|define
name|HAVE_NANOSLEEP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<ndir.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NDIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<netdb.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETDB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netgroup.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETGROUP_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<net/if_tun.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NET_IF_TUN_H
value|1
end_define

begin_comment
comment|/* Define if you are on NeXT */
end_comment

begin_comment
comment|/* #undef HAVE_NEXT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `ngetaddrinfo' function. */
end_comment

begin_comment
comment|/* #undef HAVE_NGETADDRINFO */
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
comment|/* Define to 1 if you have the `nsleep' function. */
end_comment

begin_comment
comment|/* #undef HAVE_NSLEEP */
end_comment

begin_comment
comment|/* Define to 1 if you have the `ogetaddrinfo' function. */
end_comment

begin_comment
comment|/* #undef HAVE_OGETADDRINFO */
end_comment

begin_comment
comment|/* Define if you have an old version of PAM which takes only one argument to    pam_strerror */
end_comment

begin_comment
comment|/* #undef HAVE_OLD_PAM */
end_comment

begin_comment
comment|/* Define to 1 if you have the `openlog_r' function. */
end_comment

begin_comment
comment|/* #undef HAVE_OPENLOG_R */
end_comment

begin_comment
comment|/* Define to 1 if you have the `openpty' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENPTY
value|1
end_define

begin_comment
comment|/* Define if your ssl headers are included with #include<openssl/header.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENSSL
value|1
end_define

begin_comment
comment|/* Define if you have Digital Unix Security Integration Architecture */
end_comment

begin_comment
comment|/* #undef HAVE_OSF_SIA */
end_comment

begin_comment
comment|/* Define to 1 if you have the `pam_getenvlist' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PAM_GETENVLIST
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<pam/pam_appl.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_PAM_PAM_APPL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `pam_putenv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PAM_PUTENV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<paths.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PATHS_H
value|1
end_define

begin_comment
comment|/* Define if you have ut_pid in utmp.h */
end_comment

begin_comment
comment|/* #undef HAVE_PID_IN_UTMP */
end_comment

begin_comment
comment|/* define if you have pid_t data type */
end_comment

begin_define
define|#
directive|define
name|HAVE_PID_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pledge' function. */
end_comment

begin_comment
comment|/* #undef HAVE_PLEDGE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `poll' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<poll.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `prctl' function. */
end_comment

begin_comment
comment|/* #undef HAVE_PRCTL */
end_comment

begin_comment
comment|/* Define to 1 if you have the `priv_basicset' function. */
end_comment

begin_comment
comment|/* #undef HAVE_PRIV_BASICSET */
end_comment

begin_comment
comment|/* Define to 1 if you have the<priv.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_PRIV_H */
end_comment

begin_comment
comment|/* Define if you have /proc/$pid/fd */
end_comment

begin_comment
comment|/* #undef HAVE_PROC_PID */
end_comment

begin_comment
comment|/* Define to 1 if you have the `pstat' function. */
end_comment

begin_comment
comment|/* #undef HAVE_PSTAT */
end_comment

begin_comment
comment|/* Define to 1 if you have the<pty.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_PTY_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `pututline' function. */
end_comment

begin_comment
comment|/* #undef HAVE_PUTUTLINE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `pututxline' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PUTUTXLINE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `readpassphrase' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_READPASSPHRASE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<readpassphrase.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_READPASSPHRASE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `reallocarray' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_REALLOCARRAY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `realpath' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_REALPATH
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `recvmsg' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RECVMSG
value|1
end_define

begin_comment
comment|/* sys/resource.h has RLIMIT_NPROC */
end_comment

begin_define
define|#
directive|define
name|HAVE_RLIMIT_NPROC
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* Define to 1 if you have the<rpc/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RPC_TYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `rresvport_af' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RRESVPORT_AF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `RSA_generate_key_ex' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RSA_GENERATE_KEY_EX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `RSA_get_default_method' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RSA_GET_DEFAULT_METHOD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sandbox.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SANDBOX_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `sandbox_init' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SANDBOX_INIT */
end_comment

begin_comment
comment|/* define if you have sa_family_t data type */
end_comment

begin_define
define|#
directive|define
name|HAVE_SA_FAMILY_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `scan_scaled' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SCAN_SCALED */
end_comment

begin_comment
comment|/* Define if you have SecureWare-based protected password database */
end_comment

begin_comment
comment|/* #undef HAVE_SECUREWARE */
end_comment

begin_comment
comment|/* Define to 1 if you have the<security/pam_appl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SECURITY_PAM_APPL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sendmsg' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SENDMSG
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setauthdb' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SETAUTHDB */
end_comment

begin_comment
comment|/* Define to 1 if you have the `setdtablesize' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SETDTABLESIZE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `setegid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETEGID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setenv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETENV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `seteuid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETEUID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setgroupent' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETGROUPENT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setgroups' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETGROUPS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setlinebuf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setlogin' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLOGIN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setluid' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SETLUID */
end_comment

begin_comment
comment|/* Define to 1 if you have the `setpassent' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPASSENT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setpcred' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SETPCRED */
end_comment

begin_comment
comment|/* Define to 1 if you have the `setpflags' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SETPFLAGS */
end_comment

begin_comment
comment|/* Define to 1 if you have the `setppriv' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SETPPRIV */
end_comment

begin_comment
comment|/* Define to 1 if you have the `setproctitle' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPROCTITLE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setregid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETREGID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setresgid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETRESGID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setresuid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETRESUID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setreuid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETREUID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setrlimit' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETRLIMIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setsid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETSID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setutent' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SETUTENT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `setutxdb' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETUTXDB
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setutxent' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETUTXENT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setvbuf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETVBUF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `set_id' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SET_ID */
end_comment

begin_comment
comment|/* Define to 1 if you have the `SHA256_Update' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SHA256_UPDATE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sha2.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SHA2_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<shadow.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SHADOW_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `sigaction' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sigvec' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGVEC
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `sig_atomic_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIG_ATOMIC_T
value|1
end_define

begin_comment
comment|/* define if you have size_t data type */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIZE_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `snprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SNPRINTF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `socketpair' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKETPAIR
value|1
end_define

begin_comment
comment|/* Have PEERCRED socket option */
end_comment

begin_comment
comment|/* #undef HAVE_SO_PEERCRED */
end_comment

begin_comment
comment|/* define if you have ssize_t data type */
end_comment

begin_define
define|#
directive|define
name|HAVE_SSIZE_T
value|1
end_define

begin_comment
comment|/* Fields in struct sockaddr_storage */
end_comment

begin_define
define|#
directive|define
name|HAVE_SS_FAMILY_IN_SS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `statfs' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STATFS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `statvfs' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STATVFS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stddef.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDDEF_H
value|1
end_define

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
comment|/* Define to 1 if you have the `strcasestr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCASESTR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strdup' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strerror' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strftime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRFTIME
value|1
end_define

begin_comment
comment|/* Silly mkstemp() */
end_comment

begin_comment
comment|/* #undef HAVE_STRICT_MKSTEMP */
end_comment

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
comment|/* Define to 1 if you have the `strlcat' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCAT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strlcpy' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCPY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strmode' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRMODE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strnlen' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRNLEN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strnvis' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRNVIS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strptime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRPTIME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strsep' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSEP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strtoll' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOLL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strtonum' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTONUM
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strtoul' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOUL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strtoull' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOULL
value|1
end_define

begin_comment
comment|/* define if you have struct addrinfo data type */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_ADDRINFO
value|1
end_define

begin_comment
comment|/* define if you have struct in6_addr data type */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_IN6_ADDR
value|1
end_define

begin_comment
comment|/* Define to 1 if `pw_change' is a member of `struct passwd'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_PASSWD_PW_CHANGE
value|1
end_define

begin_comment
comment|/* Define to 1 if `pw_class' is a member of `struct passwd'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_PASSWD_PW_CLASS
value|1
end_define

begin_comment
comment|/* Define to 1 if `pw_expire' is a member of `struct passwd'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_PASSWD_PW_EXPIRE
value|1
end_define

begin_comment
comment|/* Define to 1 if `pw_gecos' is a member of `struct passwd'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_PASSWD_PW_GECOS
value|1
end_define

begin_comment
comment|/* define if you have struct sockaddr_in6 data type */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_SOCKADDR_IN6
value|1
end_define

begin_comment
comment|/* Define to 1 if `sin6_scope_id' is a member of `struct sockaddr_in6'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_SOCKADDR_IN6_SIN6_SCOPE_ID
value|1
end_define

begin_comment
comment|/* define if you have struct sockaddr_storage data type */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_SOCKADDR_STORAGE
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_blksize' is a member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_BLKSIZE
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `struct timespec'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_TIMESPEC
value|1
end_define

begin_comment
comment|/* define if you have struct timeval */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_TIMEVAL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `swap32' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SWAP32 */
end_comment

begin_comment
comment|/* Define to 1 if you have the `sysconf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCONF
value|1
end_define

begin_comment
comment|/* Define if you have syslen in utmpx.h */
end_comment

begin_comment
comment|/* #undef HAVE_SYSLEN_IN_UTMPX */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/audit.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_AUDIT_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/bitypes.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_BITYPES_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/bsdtty.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_BSDTTY_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/capsicum.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_CAPSICUM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/cdefs.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_CDEFS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/dir.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_DIR_H
value|1
end_define

begin_comment
comment|/* Define if your system defines sys_errlist[] */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_ERRLIST
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/mman.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MMAN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/mount.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MOUNT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/ndir.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_NDIR_H */
end_comment

begin_comment
comment|/* Define if your system defines sys_nerr */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_NERR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/poll.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_POLL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/prctl.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PRCTL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/pstat.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PSTAT_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/ptms.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PTMS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/ptrace.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PTRACE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/select.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SELECT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/statvfs.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STATVFS_H
value|1
end_define

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
comment|/* Define to 1 if you have the<sys/stream.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STREAM_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/stropts.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STROPTS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/strtio.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STRTIO_H */
end_comment

begin_comment
comment|/* Force use of sys/syslog.h on Ultrix */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_SYSLOG_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/sysmacros.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_SYSMACROS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/timers.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMERS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
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
comment|/* Define to 1 if you have the<sys/un.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `tcgetpgrp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TCGETPGRP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `tcsendbreak' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TCSENDBREAK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `time' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have ut_time in utmp.h */
end_comment

begin_comment
comment|/* #undef HAVE_TIME_IN_UTMP */
end_comment

begin_comment
comment|/* Define if you have ut_time in utmpx.h */
end_comment

begin_comment
comment|/* #undef HAVE_TIME_IN_UTMPX */
end_comment

begin_comment
comment|/* Define to 1 if you have the `timingsafe_bcmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMINGSAFE_BCMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<tmpdir.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_TMPDIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `truncate' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TRUNCATE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<ttyent.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TTYENT_H
value|1
end_define

begin_comment
comment|/* Define if you have ut_tv in utmp.h */
end_comment

begin_comment
comment|/* #undef HAVE_TV_IN_UTMP */
end_comment

begin_comment
comment|/* Define if you have ut_tv in utmpx.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_TV_IN_UTMPX
value|1
end_define

begin_comment
comment|/* Define if you have ut_type in utmp.h */
end_comment

begin_comment
comment|/* #undef HAVE_TYPE_IN_UTMP */
end_comment

begin_comment
comment|/* Define if you have ut_type in utmpx.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_TYPE_IN_UTMPX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<ucred.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_UCRED_H */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `uintmax_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UINTMAX_T
value|1
end_define

begin_comment
comment|/* define if you have uintxx_t data type */
end_comment

begin_define
define|#
directive|define
name|HAVE_UINTXX_T
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
comment|/* Define to 1 if you have the `unsetenv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNSETENV
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `unsigned long long'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNSIGNED_LONG_LONG
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `updwtmp' function. */
end_comment

begin_comment
comment|/* #undef HAVE_UPDWTMP */
end_comment

begin_comment
comment|/* Define to 1 if you have the `updwtmpx' function. */
end_comment

begin_comment
comment|/* #undef HAVE_UPDWTMPX */
end_comment

begin_comment
comment|/* Define to 1 if you have the<usersec.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_USERSEC_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `user_from_uid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_USER_FROM_UID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `usleep' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_USLEEP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<util.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_UTIL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `utimes' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIMES
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<utime.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIME_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `utmpname' function. */
end_comment

begin_comment
comment|/* #undef HAVE_UTMPNAME */
end_comment

begin_comment
comment|/* Define to 1 if you have the `utmpxname' function. */
end_comment

begin_comment
comment|/* #undef HAVE_UTMPXNAME */
end_comment

begin_comment
comment|/* Define to 1 if you have the<utmpx.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTMPX_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<utmp.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_UTMP_H */
end_comment

begin_comment
comment|/* define if you have u_char data type */
end_comment

begin_define
define|#
directive|define
name|HAVE_U_CHAR
value|1
end_define

begin_comment
comment|/* define if you have u_int data type */
end_comment

begin_define
define|#
directive|define
name|HAVE_U_INT
value|1
end_define

begin_comment
comment|/* define if you have u_int64_t data type */
end_comment

begin_define
define|#
directive|define
name|HAVE_U_INT64_T
value|1
end_define

begin_comment
comment|/* define if you have u_intxx_t data type */
end_comment

begin_define
define|#
directive|define
name|HAVE_U_INTXX_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `vasprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VASPRINTF
value|1
end_define

begin_comment
comment|/* Define if va_copy exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_VA_COPY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<vis.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VIS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `vsnprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VSNPRINTF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `waitpid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WAITPID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `warn' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WARN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<wchar.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCHAR_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `wcwidth' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCWIDTH
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `_getlong' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE__GETLONG
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `_getpty' function. */
end_comment

begin_comment
comment|/* #undef HAVE__GETPTY */
end_comment

begin_comment
comment|/* Define to 1 if you have the `_getshort' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE__GETSHORT
value|1
end_define

begin_comment
comment|/* Define if you have struct __res_state _res as an extern */
end_comment

begin_define
define|#
directive|define
name|HAVE__RES_EXTERN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `__b64_ntop' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE___B64_NTOP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `__b64_pton' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE___B64_PTON
value|1
end_define

begin_comment
comment|/* Define if compiler implements __FUNCTION__ */
end_comment

begin_define
define|#
directive|define
name|HAVE___FUNCTION__
value|1
end_define

begin_comment
comment|/* Define if libc defines __progname */
end_comment

begin_define
define|#
directive|define
name|HAVE___PROGNAME
value|1
end_define

begin_comment
comment|/* Fields in struct sockaddr_storage */
end_comment

begin_comment
comment|/* #undef HAVE___SS_FAMILY_IN_SS */
end_comment

begin_comment
comment|/* Define if __va_copy exists */
end_comment

begin_define
define|#
directive|define
name|HAVE___VA_COPY
value|1
end_define

begin_comment
comment|/* Define if compiler implements __func__ */
end_comment

begin_define
define|#
directive|define
name|HAVE___func__
value|1
end_define

begin_comment
comment|/* Define this if you are using the Heimdal version of Kerberos V5 */
end_comment

begin_comment
comment|/* #undef HEIMDAL */
end_comment

begin_comment
comment|/* Define if you need to use IP address instead of hostname in $DISPLAY */
end_comment

begin_comment
comment|/* #undef IPADDR_IN_DISPLAY */
end_comment

begin_comment
comment|/* Detect IPv4 in IPv6 mapped addresses and treat as IPv4 */
end_comment

begin_comment
comment|/* #undef IPV4_IN_IPV6 */
end_comment

begin_comment
comment|/* Define if your system choked on IP TOS setting */
end_comment

begin_comment
comment|/* #undef IP_TOS_IS_BROKEN */
end_comment

begin_comment
comment|/* Define if you want Kerberos 5 support */
end_comment

begin_comment
comment|/* #undef KRB5 */
end_comment

begin_comment
comment|/* Define if pututxline updates lastlog too */
end_comment

begin_comment
comment|/* #undef LASTLOG_WRITE_PUTUTXLINE */
end_comment

begin_comment
comment|/* Define if you want TCP Wrappers support */
end_comment

begin_comment
comment|/* #undef LIBWRAP */
end_comment

begin_comment
comment|/* Define to whatever link() returns for "not supported" if it doesn't return    EOPNOTSUPP. */
end_comment

begin_comment
comment|/* #undef LINK_OPNOTSUPP_ERRNO */
end_comment

begin_comment
comment|/* Adjust Linux out-of-memory killer */
end_comment

begin_comment
comment|/* #undef LINUX_OOM_ADJUST */
end_comment

begin_comment
comment|/* max value of long long calculated by configure */
end_comment

begin_comment
comment|/* #undef LLONG_MAX */
end_comment

begin_comment
comment|/* min value of long long calculated by configure */
end_comment

begin_comment
comment|/* #undef LLONG_MIN */
end_comment

begin_comment
comment|/* Account locked with pw(1) */
end_comment

begin_define
define|#
directive|define
name|LOCKED_PASSWD_PREFIX
value|"*LOCKED*"
end_define

begin_comment
comment|/* String used in /etc/passwd to denote locked account */
end_comment

begin_comment
comment|/* #undef LOCKED_PASSWD_STRING */
end_comment

begin_comment
comment|/* String used in /etc/passwd to denote locked account */
end_comment

begin_comment
comment|/* #undef LOCKED_PASSWD_SUBSTR */
end_comment

begin_comment
comment|/* Some systems need a utmpx entry for /bin/login to work */
end_comment

begin_comment
comment|/* #undef LOGIN_NEEDS_UTMPX */
end_comment

begin_comment
comment|/* Set this to your mail directory if you do not have _PATH_MAILDIR */
end_comment

begin_comment
comment|/* #undef MAIL_DIRECTORY */
end_comment

begin_comment
comment|/* Need setpgrp to acquire controlling tty */
end_comment

begin_comment
comment|/* #undef NEED_SETPGRP */
end_comment

begin_comment
comment|/* compiler does not accept __attribute__ on return types */
end_comment

begin_comment
comment|/* #undef NO_ATTRIBUTE_ON_RETURN_TYPE */
end_comment

begin_comment
comment|/* Define if you don't want to use lastlog in session.c */
end_comment

begin_comment
comment|/* #undef NO_SSH_LASTLOG */
end_comment

begin_comment
comment|/* Define to disable UID restoration test */
end_comment

begin_comment
comment|/* #undef NO_UID_RESTORATION_TEST */
end_comment

begin_comment
comment|/* Define if X11 doesn't support AF_UNIX sockets on that system */
end_comment

begin_comment
comment|/* #undef NO_X11_UNIX_SOCKETS */
end_comment

begin_comment
comment|/* Define if EVP_DigestUpdate returns void */
end_comment

begin_comment
comment|/* #undef OPENSSL_EVP_DIGESTUPDATE_VOID */
end_comment

begin_comment
comment|/* OpenSSL has ECC */
end_comment

begin_define
define|#
directive|define
name|OPENSSL_HAS_ECC
value|1
end_define

begin_comment
comment|/* libcrypto has NID_X9_62_prime256v1 */
end_comment

begin_define
define|#
directive|define
name|OPENSSL_HAS_NISTP256
value|1
end_define

begin_comment
comment|/* libcrypto has NID_secp384r1 */
end_comment

begin_define
define|#
directive|define
name|OPENSSL_HAS_NISTP384
value|1
end_define

begin_comment
comment|/* libcrypto has NID_secp521r1 */
end_comment

begin_define
define|#
directive|define
name|OPENSSL_HAS_NISTP521
value|1
end_define

begin_comment
comment|/* libcrypto has EVP AES CTR */
end_comment

begin_define
define|#
directive|define
name|OPENSSL_HAVE_EVPCTR
value|1
end_define

begin_comment
comment|/* libcrypto has EVP AES GCM */
end_comment

begin_define
define|#
directive|define
name|OPENSSL_HAVE_EVPGCM
value|1
end_define

begin_comment
comment|/* libcrypto is missing AES 192 and 256 bit functions */
end_comment

begin_comment
comment|/* #undef OPENSSL_LOBOTOMISED_AES */
end_comment

begin_comment
comment|/* Define if you want the OpenSSL internally seeded PRNG only */
end_comment

begin_define
define|#
directive|define
name|OPENSSL_PRNG_ONLY
value|1
end_define

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|"openssh-unix-dev@mindrot.org"
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"OpenSSH"
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"OpenSSH Portable"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"openssh"
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
value|"Portable"
end_define

begin_comment
comment|/* Define if you are using Solaris-derived PAM which passes pam_messages to    the conversation function with an extra level of indirection */
end_comment

begin_comment
comment|/* #undef PAM_SUN_CODEBASE */
end_comment

begin_comment
comment|/* Work around problematic Linux PAM modules handling of PAM_TTY */
end_comment

begin_comment
comment|/* #undef PAM_TTY_KLUDGE */
end_comment

begin_comment
comment|/* must supply username to passwd */
end_comment

begin_comment
comment|/* #undef PASSWD_NEEDS_USERNAME */
end_comment

begin_comment
comment|/* System dirs owned by bin (uid 2) */
end_comment

begin_comment
comment|/* #undef PLATFORM_SYS_DIR_UID */
end_comment

begin_comment
comment|/* Port number of PRNGD/EGD random number socket */
end_comment

begin_comment
comment|/* #undef PRNGD_PORT */
end_comment

begin_comment
comment|/* Location of PRNGD/EGD random number socket */
end_comment

begin_comment
comment|/* #undef PRNGD_SOCKET */
end_comment

begin_comment
comment|/* read(1) can return 0 for a non-closed fd */
end_comment

begin_comment
comment|/* #undef PTY_ZEROREAD */
end_comment

begin_comment
comment|/* Sandbox using capsicum */
end_comment

begin_define
define|#
directive|define
name|SANDBOX_CAPSICUM
value|1
end_define

begin_comment
comment|/* Sandbox using Darwin sandbox_init(3) */
end_comment

begin_comment
comment|/* #undef SANDBOX_DARWIN */
end_comment

begin_comment
comment|/* no privsep sandboxing */
end_comment

begin_comment
comment|/* #undef SANDBOX_NULL */
end_comment

begin_comment
comment|/* Sandbox using pledge(2) */
end_comment

begin_comment
comment|/* #undef SANDBOX_PLEDGE */
end_comment

begin_comment
comment|/* Sandbox using setrlimit(2) */
end_comment

begin_comment
comment|/* #undef SANDBOX_RLIMIT */
end_comment

begin_comment
comment|/* Sandbox using seccomp filter */
end_comment

begin_comment
comment|/* #undef SANDBOX_SECCOMP_FILTER */
end_comment

begin_comment
comment|/* setrlimit RLIMIT_FSIZE works */
end_comment

begin_comment
comment|/* #undef SANDBOX_SKIP_RLIMIT_FSIZE */
end_comment

begin_comment
comment|/* define if setrlimit RLIMIT_NOFILE breaks things */
end_comment

begin_define
define|#
directive|define
name|SANDBOX_SKIP_RLIMIT_NOFILE
value|1
end_define

begin_comment
comment|/* Sandbox using Solaris/Illumos privileges */
end_comment

begin_comment
comment|/* #undef SANDBOX_SOLARIS */
end_comment

begin_comment
comment|/* Sandbox using systrace(4) */
end_comment

begin_comment
comment|/* #undef SANDBOX_SYSTRACE */
end_comment

begin_comment
comment|/* Specify the system call convention in use */
end_comment

begin_comment
comment|/* #undef SECCOMP_AUDIT_ARCH */
end_comment

begin_comment
comment|/* Define if your platform breaks doing a seteuid before a setuid */
end_comment

begin_comment
comment|/* #undef SETEUID_BREAKS_SETUID */
end_comment

begin_comment
comment|/* The size of `int', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_INT
value|4
end_define

begin_comment
comment|/* The size of `long int', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_LONG_INT
value|8
end_define

begin_comment
comment|/* The size of `long long int', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_LONG_LONG_INT
value|8
end_define

begin_comment
comment|/* The size of `short int', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_SHORT_INT
value|2
end_define

begin_comment
comment|/* Define if you want S/Key support */
end_comment

begin_comment
comment|/* #undef SKEY */
end_comment

begin_comment
comment|/* Define if your skeychallenge() function takes 4 arguments (NetBSD) */
end_comment

begin_comment
comment|/* #undef SKEYCHALLENGE_4ARG */
end_comment

begin_comment
comment|/* Define as const if snprintf() can declare const char *fmt */
end_comment

begin_define
define|#
directive|define
name|SNPRINTF_CONST
value|const
end_define

begin_comment
comment|/* Define to a Set Process Title type if your system is supported by    bsd-setproctitle.c */
end_comment

begin_comment
comment|/* #undef SPT_TYPE */
end_comment

begin_comment
comment|/* Define if sshd somehow reacquires a controlling TTY after setsid() */
end_comment

begin_comment
comment|/* #undef SSHD_ACQUIRES_CTTY */
end_comment

begin_comment
comment|/* sshd PAM service name */
end_comment

begin_comment
comment|/* #undef SSHD_PAM_SERVICE */
end_comment

begin_comment
comment|/* Define if pam_chauthtok wants real uid set to the unpriv'ed user */
end_comment

begin_comment
comment|/* #undef SSHPAM_CHAUTHTOK_NEEDS_RUID */
end_comment

begin_comment
comment|/* Use audit debugging module */
end_comment

begin_comment
comment|/* #undef SSH_AUDIT_EVENTS */
end_comment

begin_comment
comment|/* Windows is sensitive to read buffer size */
end_comment

begin_comment
comment|/* #undef SSH_IOBUFSZ */
end_comment

begin_comment
comment|/* non-privileged user for privilege separation */
end_comment

begin_define
define|#
directive|define
name|SSH_PRIVSEP_USER
value|"sshd"
end_define

begin_comment
comment|/* Use tunnel device compatibility to OpenBSD */
end_comment

begin_comment
comment|/* #undef SSH_TUN_COMPAT_AF */
end_comment

begin_comment
comment|/* Open tunnel devices the FreeBSD way */
end_comment

begin_define
define|#
directive|define
name|SSH_TUN_FREEBSD
value|1
end_define

begin_comment
comment|/* Open tunnel devices the Linux tun/tap way */
end_comment

begin_comment
comment|/* #undef SSH_TUN_LINUX */
end_comment

begin_comment
comment|/* No layer 2 tunnel support */
end_comment

begin_comment
comment|/* #undef SSH_TUN_NO_L2 */
end_comment

begin_comment
comment|/* Open tunnel devices the OpenBSD way */
end_comment

begin_comment
comment|/* #undef SSH_TUN_OPENBSD */
end_comment

begin_comment
comment|/* Prepend the address family to IP tunnel traffic */
end_comment

begin_comment
comment|/* #undef SSH_TUN_PREPEND_AF */
end_comment

begin_comment
comment|/* Define to 1 if you have the ANSI C header files. */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define if you want a different $PATH for the superuser */
end_comment

begin_comment
comment|/* #undef SUPERUSER_PATH */
end_comment

begin_comment
comment|/* syslog_r function is safe to use in in a signal handler */
end_comment

begin_comment
comment|/* #undef SYSLOG_R_SAFE_IN_SIGHAND */
end_comment

begin_comment
comment|/* Support passwords> 8 chars */
end_comment

begin_comment
comment|/* #undef UNIXWARE_LONG_PASSWORDS */
end_comment

begin_comment
comment|/* Specify default $PATH */
end_comment

begin_comment
comment|/* #undef USER_PATH */
end_comment

begin_comment
comment|/* Define this if you want to use libkafs' AFS support */
end_comment

begin_comment
comment|/* #undef USE_AFS */
end_comment

begin_comment
comment|/* Use BSM audit module */
end_comment

begin_comment
comment|/* #undef USE_BSM_AUDIT */
end_comment

begin_comment
comment|/* Use btmp to log bad logins */
end_comment

begin_comment
comment|/* #undef USE_BTMP */
end_comment

begin_comment
comment|/* Use libedit for sftp */
end_comment

begin_define
define|#
directive|define
name|USE_LIBEDIT
value|1
end_define

begin_comment
comment|/* Use Linux audit module */
end_comment

begin_comment
comment|/* #undef USE_LINUX_AUDIT */
end_comment

begin_comment
comment|/* Enable OpenSSL engine support */
end_comment

begin_define
define|#
directive|define
name|USE_OPENSSL_ENGINE
value|1
end_define

begin_comment
comment|/* Define if you want to enable PAM support */
end_comment

begin_define
define|#
directive|define
name|USE_PAM
value|1
end_define

begin_comment
comment|/* Use PIPES instead of a socketpair() */
end_comment

begin_comment
comment|/* #undef USE_PIPES */
end_comment

begin_comment
comment|/* Define if you have Solaris privileges */
end_comment

begin_comment
comment|/* #undef USE_SOLARIS_PRIVS */
end_comment

begin_comment
comment|/* Define if you have Solaris process contracts */
end_comment

begin_comment
comment|/* #undef USE_SOLARIS_PROCESS_CONTRACTS */
end_comment

begin_comment
comment|/* Define if you have Solaris projects */
end_comment

begin_comment
comment|/* #undef USE_SOLARIS_PROJECTS */
end_comment

begin_comment
comment|/* Define if you shouldn't strip 'tty' from your ttyname in [uw]tmp */
end_comment

begin_comment
comment|/* #undef WITH_ABBREV_NO_TTY */
end_comment

begin_comment
comment|/* Define if you want to enable AIX4's authenticate function */
end_comment

begin_comment
comment|/* #undef WITH_AIXAUTHENTICATE */
end_comment

begin_comment
comment|/* Define if you have/want arrays (cluster-wide session managment, not C    arrays) */
end_comment

begin_comment
comment|/* #undef WITH_IRIX_ARRAY */
end_comment

begin_comment
comment|/* Define if you want IRIX audit trails */
end_comment

begin_comment
comment|/* #undef WITH_IRIX_AUDIT */
end_comment

begin_comment
comment|/* Define if you want IRIX kernel jobs */
end_comment

begin_comment
comment|/* #undef WITH_IRIX_JOBS */
end_comment

begin_comment
comment|/* Define if you want IRIX project management */
end_comment

begin_comment
comment|/* #undef WITH_IRIX_PROJECT */
end_comment

begin_comment
comment|/* use libcrypto for cryptography */
end_comment

begin_define
define|#
directive|define
name|WITH_OPENSSL
value|1
end_define

begin_comment
comment|/* Define if you want SELinux support. */
end_comment

begin_comment
comment|/* #undef WITH_SELINUX */
end_comment

begin_comment
comment|/* include SSH protocol version 1 support */
end_comment

begin_comment
comment|/* #undef WITH_SSH1 */
end_comment

begin_comment
comment|/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most    significant byte first (like Motorola and SPARC, unlike Intel). */
end_comment

begin_if
if|#
directive|if
name|defined
name|AC_APPLE_UNIVERSAL_BUILD
end_if

begin_if
if|#
directive|if
name|defined
name|__BIG_ENDIAN__
end_if

begin_define
define|#
directive|define
name|WORDS_BIGENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|WORDS_BIGENDIAN
end_ifndef

begin_comment
comment|/* #  undef WORDS_BIGENDIAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if xauth is found in your path */
end_comment

begin_comment
comment|/* #undef XAUTH_PATH */
end_comment

begin_comment
comment|/* Enable large inode numbers on Mac OS X 10.5.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DARWIN_USE_64_BIT_INODE
end_ifndef

begin_define
define|#
directive|define
name|_DARWIN_USE_64_BIT_INODE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in a file offset, on hosts where this is settable. */
end_comment

begin_comment
comment|/* #undef _FILE_OFFSET_BITS */
end_comment

begin_comment
comment|/* Define for large files, on AIX-style hosts. */
end_comment

begin_comment
comment|/* #undef _LARGE_FILES */
end_comment

begin_comment
comment|/* log for bad login attempts */
end_comment

begin_comment
comment|/* #undef _PATH_BTMP */
end_comment

begin_comment
comment|/* Full path of your "passwd" program */
end_comment

begin_define
define|#
directive|define
name|_PATH_PASSWD_PROG
value|"/usr/bin/passwd"
end_define

begin_comment
comment|/* Specify location of ssh.pid */
end_comment

begin_define
define|#
directive|define
name|_PATH_SSH_PIDDIR
value|"/var/run"
end_define

begin_comment
comment|/* Define if we don't have struct __res_state in resolv.h */
end_comment

begin_comment
comment|/* #undef __res_state */
end_comment

begin_comment
comment|/* Define to `__inline__' or `__inline' if that's what the C compiler    calls it, or to nothing if 'inline' is not supported under any name.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_comment
comment|/* #undef inline */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* type to use in place of socklen_t if not defined */
end_comment

begin_comment
comment|/* #undef socklen_t */
end_comment

end_unit

