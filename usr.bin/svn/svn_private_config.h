begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* subversion/svn_private_config.h.tmp.  Generated from svn_private_config.h.in by configure.  */
end_comment

begin_comment
comment|/* subversion/svn_private_config.h.in.  Generated from configure.ac by autoheader.  */
end_comment

begin_comment
comment|/* The fs type to use by default */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_FS_TYPE
value|"fsfs"
end_define

begin_comment
comment|/* The http library to use by default */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_HTTP_LIBRARY
value|"serf"
end_define

begin_comment
comment|/* Define to 1 if Ev2 implementations should be used. */
end_comment

begin_comment
comment|/* #undef ENABLE_EV2_IMPL */
end_comment

begin_comment
comment|/* Define to 1 if translation of program messages to the user's native    language is requested. */
end_comment

begin_comment
comment|/* #undef ENABLE_NLS */
end_comment

begin_comment
comment|/* Define to 1 if you have the `bind_textdomain_codeset' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_BIND_TEXTDOMAIN_CODESET
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<dlfcn.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DLFCN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you don't have `vprintf' but do have `_doprnt.' */
end_comment

begin_comment
comment|/* #undef HAVE_DOPRNT */
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
comment|/* Define to 1 if you have the `iconv' library (-liconv). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBICONV */
end_comment

begin_comment
comment|/* Define to 1 if you have the `socket' library (-lsocket). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSOCKET */
end_comment

begin_comment
comment|/* Define to 1 if you have the<magic.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MAGIC_H */
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
comment|/* Define to 1 if you have the `rb_errinfo' function. */
end_comment

begin_comment
comment|/* #undef HAVE_RB_ERRINFO */
end_comment

begin_comment
comment|/* Define to 1 if you have the `readlink' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_READLINK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<serf.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SERF_H
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
comment|/* Define to 1 if you have the `symlink' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYMLINK
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
comment|/* Define to 1 if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/utsname.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UTSNAME_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `tcgetattr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TCGETATTR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `tcsetattr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TCSETATTR
value|1
end_define

begin_comment
comment|/* Defined if we have a usable termios library. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `uname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNAME
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
comment|/* Define to 1 if you have the `vprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VPRINTF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<zlib.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_ZLIB_H */
end_comment

begin_comment
comment|/* Define to the sub-directory in which libtool stores uninstalled libraries.    */
end_comment

begin_define
define|#
directive|define
name|LT_OBJDIR
value|".libs/"
end_define

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|"http://subversion.apache.org/"
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"subversion"
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"subversion 1.8.10"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"subversion"
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
value|"1.8.10"
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

begin_comment
comment|/* Define to the Python/C API format character suitable for apr_int64_t */
end_comment

begin_define
define|#
directive|define
name|SVN_APR_INT64_T_PYCFMT
value|"l"
end_define

begin_comment
comment|/* Define if circular linkage is not possible on this platform. */
end_comment

begin_comment
comment|/* #undef SVN_AVOID_CIRCULAR_LINKAGE_AT_ALL_COSTS_HACK */
end_comment

begin_comment
comment|/* Defined to be the path to the installed binaries */
end_comment

begin_define
define|#
directive|define
name|SVN_BINDIR
value|"/usr/bin"
end_define

begin_comment
comment|/* Defined to the config.guess name of the build system */
end_comment

begin_define
define|#
directive|define
name|SVN_BUILD_HOST
value|"bikeshed-malachite-topaz-amber-freebsd"
end_define

begin_comment
comment|/* Defined to the config.guess name of the build target */
end_comment

begin_define
define|#
directive|define
name|SVN_BUILD_TARGET
value|"bikeshed-malachite-topaz-amber-freebsd"
end_define

begin_comment
comment|/* The path of a default editor for the client. */
end_comment

begin_comment
comment|/* #undef SVN_CLIENT_EDITOR */
end_comment

begin_comment
comment|/* Defined if the full version matching rules are disabled */
end_comment

begin_comment
comment|/* #undef SVN_DISABLE_FULL_VERSION_MATCH */
end_comment

begin_comment
comment|/* Defined if plaintext password/passphrase storage is disabled */
end_comment

begin_comment
comment|/* #undef SVN_DISABLE_PLAINTEXT_PASSWORD_STORAGE */
end_comment

begin_comment
comment|/* The desired major version for the Berkeley DB */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_WANT_DB_MAJOR
value|4
end_define

begin_comment
comment|/* The desired minor version for the Berkeley DB */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_WANT_DB_MINOR
value|0
end_define

begin_comment
comment|/* The desired patch version for the Berkeley DB */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_WANT_DB_PATCH
value|14
end_define

begin_comment
comment|/* Define if compiler provides atomic builtins */
end_comment

begin_define
define|#
directive|define
name|SVN_HAS_ATOMIC_BUILTINS
value|0
end_define

begin_comment
comment|/* Is GNOME Keyring support enabled? */
end_comment

begin_comment
comment|/* #undef SVN_HAVE_GNOME_KEYRING */
end_comment

begin_comment
comment|/* Is GPG Agent support enabled? */
end_comment

begin_define
define|#
directive|define
name|SVN_HAVE_GPG_AGENT
value|1
end_define

begin_comment
comment|/* Is Mac OS KeyChain support enabled? */
end_comment

begin_comment
comment|/* #undef SVN_HAVE_KEYCHAIN_SERVICES */
end_comment

begin_comment
comment|/* Defined if KWallet support is enabled */
end_comment

begin_comment
comment|/* #undef SVN_HAVE_KWALLET */
end_comment

begin_comment
comment|/* Defined if libmagic support is enabled */
end_comment

begin_define
define|#
directive|define
name|SVN_HAVE_LIBMAGIC
value|1
end_define

begin_comment
comment|/* Is Mach-O low-level _dyld API available? */
end_comment

begin_comment
comment|/* #undef SVN_HAVE_MACHO_ITERATE */
end_comment

begin_comment
comment|/* Is Mac OS property list API available? */
end_comment

begin_comment
comment|/* #undef SVN_HAVE_MACOS_PLIST */
end_comment

begin_comment
comment|/* Defined if apr_memcache (standalone or in apr-util) is present */
end_comment

begin_define
define|#
directive|define
name|SVN_HAVE_MEMCACHE
value|1
end_define

begin_comment
comment|/* Defined if Expat 1.0 or 1.1 was found */
end_comment

begin_comment
comment|/* #undef SVN_HAVE_OLD_EXPAT */
end_comment

begin_comment
comment|/* Defined if Cyrus SASL v2 is present on the system */
end_comment

begin_comment
comment|/* #undef SVN_HAVE_SASL */
end_comment

begin_comment
comment|/* Defined if support for Serf is enabled */
end_comment

begin_define
define|#
directive|define
name|SVN_HAVE_SERF
value|1
end_define

begin_comment
comment|/* Defined if libsvn_client should link against libsvn_ra_local */
end_comment

begin_define
define|#
directive|define
name|SVN_LIBSVN_CLIENT_LINKS_RA_LOCAL
value|1
end_define

begin_comment
comment|/* Defined if libsvn_client should link against libsvn_ra_serf */
end_comment

begin_define
define|#
directive|define
name|SVN_LIBSVN_CLIENT_LINKS_RA_SERF
value|1
end_define

begin_comment
comment|/* Defined if libsvn_client should link against libsvn_ra_svn */
end_comment

begin_define
define|#
directive|define
name|SVN_LIBSVN_CLIENT_LINKS_RA_SVN
value|1
end_define

begin_comment
comment|/* Defined if libsvn_fs should link against libsvn_fs_base */
end_comment

begin_comment
comment|/* #undef SVN_LIBSVN_FS_LINKS_FS_BASE */
end_comment

begin_comment
comment|/* Defined if libsvn_fs should link against libsvn_fs_fs */
end_comment

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_LINKS_FS_FS
value|1
end_define

begin_comment
comment|/* Defined to be the path to the installed locale dirs */
end_comment

begin_define
define|#
directive|define
name|SVN_LOCALE_DIR
value|"NONE/share/locale"
end_define

begin_comment
comment|/* Defined to be the null device for the system */
end_comment

begin_define
define|#
directive|define
name|SVN_NULL_DEVICE_NAME
value|"/dev/null"
end_define

begin_comment
comment|/* Defined to be the path separator used on your local filesystem */
end_comment

begin_define
define|#
directive|define
name|SVN_PATH_LOCAL_SEPARATOR
value|'/'
end_define

begin_comment
comment|/* Subversion library major verson */
end_comment

begin_define
define|#
directive|define
name|SVN_SOVERSION
value|0
end_define

begin_comment
comment|/* Defined if svn should use the amalgamated version of sqlite */
end_comment

begin_comment
comment|/* #undef SVN_SQLITE_INLINE */
end_comment

begin_comment
comment|/* Defined if svn should try to load DSOs */
end_comment

begin_comment
comment|/* #undef SVN_USE_DSO */
end_comment

begin_comment
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVN_WANT_BDB
end_ifdef

begin_define
define|#
directive|define
name|APU_WANT_DB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Indicate to translators that string X should be translated.  Do not look    up the translation at run time; just expand to X.  This macro is suitable    for use where a constant string is required at compile time. */
end_comment

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_comment
comment|/* Indicate to translators that we have decided the string X should not be    translated.  Expand to X. */
end_comment

begin_define
define|#
directive|define
name|U_
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_NLS
end_ifdef

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_comment
comment|/* Indicate to translators that string X should be translated.  At run time,    look up and return the translation of X. */
end_comment

begin_define
define|#
directive|define
name|_
parameter_list|(
name|x
parameter_list|)
value|dgettext(PACKAGE_NAME, x)
end_define

begin_comment
comment|/* Indicate to translators that strings X1 and X2 are singular and plural    forms of the same message, and should be translated.  At run time, return    an appropriate translation depending on the number N. */
end_comment

begin_define
define|#
directive|define
name|Q_
parameter_list|(
name|x1
parameter_list|,
name|x2
parameter_list|,
name|n
parameter_list|)
value|dngettext(PACKAGE_NAME, x1, x2, n)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|Q_
parameter_list|(
name|x1
parameter_list|,
name|x2
parameter_list|,
name|n
parameter_list|)
value|(((n) == 1) ? x1 : x2)
end_define

begin_define
define|#
directive|define
name|gettext
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|dgettext
parameter_list|(
name|domain
parameter_list|,
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

