begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h.  Generated from config.h.in by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated from configure.ac by autoheader.  */
end_comment

begin_comment
comment|/* MD5 via ARCHIVE_CRYPTO_MD5_LIBC supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_MD5_LIBC */
end_comment

begin_comment
comment|/* MD5 via ARCHIVE_CRYPTO_MD5_LIBMD supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_MD5_LIBMD */
end_comment

begin_comment
comment|/* MD5 via ARCHIVE_CRYPTO_MD5_LIBSYSTEM supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_MD5_LIBSYSTEM */
end_comment

begin_comment
comment|/* MD5 via ARCHIVE_CRYPTO_MD5_NETTLE supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_MD5_NETTLE */
end_comment

begin_comment
comment|/* MD5 via ARCHIVE_CRYPTO_MD5_OPENSSL supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_MD5_OPENSSL */
end_comment

begin_comment
comment|/* MD5 via ARCHIVE_CRYPTO_MD5_WIN supported. */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_MD5_WIN
value|1
end_define

begin_comment
comment|/* RMD160 via ARCHIVE_CRYPTO_RMD160_LIBC supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_RMD160_LIBC */
end_comment

begin_comment
comment|/* RMD160 via ARCHIVE_CRYPTO_RMD160_LIBMD supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_RMD160_LIBMD */
end_comment

begin_comment
comment|/* RMD160 via ARCHIVE_CRYPTO_RMD160_NETTLE supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_RMD160_NETTLE */
end_comment

begin_comment
comment|/* RMD160 via ARCHIVE_CRYPTO_RMD160_OPENSSL supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_RMD160_OPENSSL */
end_comment

begin_comment
comment|/* SHA1 via ARCHIVE_CRYPTO_SHA1_LIBC supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA1_LIBC */
end_comment

begin_comment
comment|/* SHA1 via ARCHIVE_CRYPTO_SHA1_LIBMD supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA1_LIBMD */
end_comment

begin_comment
comment|/* SHA1 via ARCHIVE_CRYPTO_SHA1_LIBSYSTEM supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA1_LIBSYSTEM */
end_comment

begin_comment
comment|/* SHA1 via ARCHIVE_CRYPTO_SHA1_NETTLE supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA1_NETTLE */
end_comment

begin_comment
comment|/* SHA1 via ARCHIVE_CRYPTO_SHA1_OPENSSL supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA1_OPENSSL */
end_comment

begin_comment
comment|/* SHA1 via ARCHIVE_CRYPTO_SHA1_WIN supported. */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_SHA1_WIN
value|1
end_define

begin_comment
comment|/* SHA256 via ARCHIVE_CRYPTO_SHA256_LIBC supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA256_LIBC */
end_comment

begin_comment
comment|/* SHA256 via ARCHIVE_CRYPTO_SHA256_LIBC2 supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA256_LIBC2 */
end_comment

begin_comment
comment|/* SHA256 via ARCHIVE_CRYPTO_SHA256_LIBC3 supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA256_LIBC3 */
end_comment

begin_comment
comment|/* SHA256 via ARCHIVE_CRYPTO_SHA256_LIBMD supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA256_LIBMD */
end_comment

begin_comment
comment|/* SHA256 via ARCHIVE_CRYPTO_SHA256_LIBSYSTEM supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA256_LIBSYSTEM */
end_comment

begin_comment
comment|/* SHA256 via ARCHIVE_CRYPTO_SHA256_NETTLE supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA256_NETTLE */
end_comment

begin_comment
comment|/* SHA256 via ARCHIVE_CRYPTO_SHA256_OPENSSL supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA256_OPENSSL */
end_comment

begin_comment
comment|/* SHA256 via ARCHIVE_CRYPTO_SHA256_WIN supported. */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_SHA256_WIN
value|1
end_define

begin_comment
comment|/* SHA384 via ARCHIVE_CRYPTO_SHA384_LIBC supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA384_LIBC */
end_comment

begin_comment
comment|/* SHA384 via ARCHIVE_CRYPTO_SHA384_LIBC2 supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA384_LIBC2 */
end_comment

begin_comment
comment|/* SHA384 via ARCHIVE_CRYPTO_SHA384_LIBC3 supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA384_LIBC3 */
end_comment

begin_comment
comment|/* SHA384 via ARCHIVE_CRYPTO_SHA384_LIBSYSTEM supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA384_LIBSYSTEM */
end_comment

begin_comment
comment|/* SHA384 via ARCHIVE_CRYPTO_SHA384_NETTLE supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA384_NETTLE */
end_comment

begin_comment
comment|/* SHA384 via ARCHIVE_CRYPTO_SHA384_OPENSSL supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA384_OPENSSL */
end_comment

begin_comment
comment|/* SHA384 via ARCHIVE_CRYPTO_SHA384_WIN supported. */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_SHA384_WIN
value|1
end_define

begin_comment
comment|/* SHA512 via ARCHIVE_CRYPTO_SHA512_LIBC supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA512_LIBC */
end_comment

begin_comment
comment|/* SHA512 via ARCHIVE_CRYPTO_SHA512_LIBC2 supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA512_LIBC2 */
end_comment

begin_comment
comment|/* SHA512 via ARCHIVE_CRYPTO_SHA512_LIBC3 supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA512_LIBC3 */
end_comment

begin_comment
comment|/* SHA512 via ARCHIVE_CRYPTO_SHA512_LIBMD supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA512_LIBMD */
end_comment

begin_comment
comment|/* SHA512 via ARCHIVE_CRYPTO_SHA512_LIBSYSTEM supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA512_LIBSYSTEM */
end_comment

begin_comment
comment|/* SHA512 via ARCHIVE_CRYPTO_SHA512_NETTLE supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA512_NETTLE */
end_comment

begin_comment
comment|/* SHA512 via ARCHIVE_CRYPTO_SHA512_OPENSSL supported. */
end_comment

begin_comment
comment|/* #undef ARCHIVE_CRYPTO_SHA512_OPENSSL */
end_comment

begin_comment
comment|/* SHA512 via ARCHIVE_CRYPTO_SHA512_WIN supported. */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_SHA512_WIN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `acl_create_entry' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ACL_CREATE_ENTRY */
end_comment

begin_comment
comment|/* Define to 1 if you have the `acl_get_link' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ACL_GET_LINK */
end_comment

begin_comment
comment|/* Define to 1 if you have the `acl_get_link_np' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ACL_GET_LINK_NP */
end_comment

begin_comment
comment|/* Define to 1 if you have the `acl_get_perm' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ACL_GET_PERM */
end_comment

begin_comment
comment|/* Define to 1 if you have the `acl_get_perm_np' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ACL_GET_PERM_NP */
end_comment

begin_comment
comment|/* Define to 1 if you have the `acl_init' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ACL_INIT */
end_comment

begin_comment
comment|/* Define to 1 if you have the<acl/libacl.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_ACL_LIBACL_H */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `acl_permset_t'. */
end_comment

begin_comment
comment|/* #undef HAVE_ACL_PERMSET_T */
end_comment

begin_comment
comment|/* Define to 1 if you have the `acl_set_fd' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ACL_SET_FD */
end_comment

begin_comment
comment|/* Define to 1 if you have the `acl_set_fd_np' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ACL_SET_FD_NP */
end_comment

begin_comment
comment|/* Define to 1 if you have the `acl_set_file' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ACL_SET_FILE */
end_comment

begin_comment
comment|/* True for systems with POSIX ACL support */
end_comment

begin_comment
comment|/* #undef HAVE_ACL_USER */
end_comment

begin_comment
comment|/* Define to 1 if you have the `arc4random_buf' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ARC4RANDOM_BUF */
end_comment

begin_comment
comment|/* Define to 1 if you have the<attr/xattr.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_ATTR_XATTR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<Bcrypt.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_BCRYPT_H
end_define

begin_comment
comment|/* Define to 1 if you have the<bzlib.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_BZLIB_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `chflags' function. */
end_comment

begin_comment
comment|/* #undef HAVE_CHFLAGS */
end_comment

begin_comment
comment|/* Define to 1 if you have the `chown' function. */
end_comment

begin_comment
comment|/* #undef HAVE_CHOWN */
end_comment

begin_comment
comment|/* Define to 1 if you have the `chroot' function. */
end_comment

begin_comment
comment|/* #undef HAVE_CHROOT */
end_comment

begin_comment
comment|/* Define to 1 if you have the<copyfile.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_COPYFILE_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `ctime_r' function. */
end_comment

begin_comment
comment|/* #undef HAVE_CTIME_R */
end_comment

begin_comment
comment|/* Define to 1 if you have the<ctype.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CTYPE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `cygwin_conv_path' function. */
end_comment

begin_comment
comment|/* #undef HAVE_CYGWIN_CONV_PATH */
end_comment

begin_comment
comment|/* Define to 1 if you have the declaration of `EXTATTR_NAMESPACE_USER', and to    0 if you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_EXTATTR_NAMESPACE_USER
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `INT64_MAX', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_INT64_MAX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `INT64_MIN', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_INT64_MIN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `SIZE_MAX', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_SIZE_MAX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `SSIZE_MAX', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_SSIZE_MAX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `strerror_r', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRERROR_R
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `UINT32_MAX', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_UINT32_MAX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `UINT64_MAX', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_UINT64_MAX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<dirent.h> header file, and it defines `DIR'.    */
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

begin_comment
comment|/* #undef HAVE_DIRFD */
end_comment

begin_comment
comment|/* Define to 1 if you have the<dlfcn.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_DLFCN_H */
end_comment

begin_comment
comment|/* Define to 1 if you don't have `vprintf' but do have `_doprnt.' */
end_comment

begin_comment
comment|/* #undef HAVE_DOPRNT */
end_comment

begin_comment
comment|/* Define to 1 if nl_langinfo supports D_MD_ORDER */
end_comment

begin_comment
comment|/* #undef HAVE_D_MD_ORDER */
end_comment

begin_comment
comment|/* A possible errno value for invalid file format errors */
end_comment

begin_comment
comment|/* #undef HAVE_EFTYPE */
end_comment

begin_comment
comment|/* A possible errno value for invalid file format errors */
end_comment

begin_define
define|#
directive|define
name|HAVE_EILSEQ
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<errno.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<expat.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_EXPAT_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<ext2fs/ext2_fs.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_EXT2FS_EXT2_FS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `extattr_get_file' function. */
end_comment

begin_comment
comment|/* #undef HAVE_EXTATTR_GET_FILE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `extattr_list_file' function. */
end_comment

begin_comment
comment|/* #undef HAVE_EXTATTR_LIST_FILE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `extattr_set_fd' function. */
end_comment

begin_comment
comment|/* #undef HAVE_EXTATTR_SET_FD */
end_comment

begin_comment
comment|/* Define to 1 if you have the `extattr_set_file' function. */
end_comment

begin_comment
comment|/* #undef HAVE_EXTATTR_SET_FILE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `fchdir' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FCHDIR */
end_comment

begin_comment
comment|/* Define to 1 if you have the `fchflags' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FCHFLAGS */
end_comment

begin_comment
comment|/* Define to 1 if you have the `fchmod' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FCHMOD */
end_comment

begin_comment
comment|/* Define to 1 if you have the `fchown' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FCHOWN */
end_comment

begin_comment
comment|/* Define to 1 if you have the `fcntl' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FCNTL */
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
comment|/* Define to 1 if you have the `fdopendir' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FDOPENDIR */
end_comment

begin_comment
comment|/* Define to 1 if you have the `fgetea' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FGETEA */
end_comment

begin_comment
comment|/* Define to 1 if you have the `fgetxattr' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FGETXATTR */
end_comment

begin_comment
comment|/* Define to 1 if you have the `flistea' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FLISTEA */
end_comment

begin_comment
comment|/* Define to 1 if you have the `flistxattr' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FLISTXATTR */
end_comment

begin_comment
comment|/* Define to 1 if you have the `fork' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FORK */
end_comment

begin_comment
comment|/* Define to 1 if fseeko (and presumably ftello) exists and is declared. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FSEEKO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fsetea' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FSETEA */
end_comment

begin_comment
comment|/* Define to 1 if you have the `fsetxattr' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FSETXATTR */
end_comment

begin_comment
comment|/* Define to 1 if you have the `fstat' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FSTAT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fstatat' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FSTATAT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `fstatfs' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FSTATFS */
end_comment

begin_comment
comment|/* Define to 1 if you have the `fstatvfs' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FSTATVFS */
end_comment

begin_comment
comment|/* Define to 1 if you have the `ftruncate' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FTRUNCATE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `futimens' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FUTIMENS */
end_comment

begin_comment
comment|/* Define to 1 if you have the `futimes' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FUTIMES */
end_comment

begin_comment
comment|/* Define to 1 if you have the `futimesat' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FUTIMESAT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getea' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETEA */
end_comment

begin_comment
comment|/* Define to 1 if you have the `geteuid' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETEUID */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getgrgid_r' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETGRGID_R */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getgrnam_r' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETGRNAM_R */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getpid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpwnam_r' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETPWNAM_R */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getpwuid_r' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETPWUID_R */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getvfsbyname' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETVFSBYNAME */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getxattr' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETXATTR */
end_comment

begin_comment
comment|/* Define to 1 if you have the `gmtime_r' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GMTIME_R */
end_comment

begin_comment
comment|/* Define to 1 if you have the<grp.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_GRP_H */
end_comment

begin_comment
comment|/* Define if you have the iconv() function and it works. */
end_comment

begin_comment
comment|/* #undef HAVE_ICONV */
end_comment

begin_comment
comment|/* Define to 1 if you have the<iconv.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_ICONV_H */
end_comment

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
comment|/* Define to 1 if you have the<io.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_IO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<langinfo.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LANGINFO_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `lchflags' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LCHFLAGS */
end_comment

begin_comment
comment|/* Define to 1 if you have the `lchmod' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LCHMOD */
end_comment

begin_comment
comment|/* Define to 1 if you have the `lchown' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LCHOWN */
end_comment

begin_comment
comment|/* Define to 1 if you have the `lgetea' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LGETEA */
end_comment

begin_comment
comment|/* Define to 1 if you have the `lgetxattr' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LGETXATTR */
end_comment

begin_comment
comment|/* Define to 1 if you have the `acl' library (-lacl). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBACL */
end_comment

begin_comment
comment|/* Define to 1 if you have the `attr' library (-lattr). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBATTR */
end_comment

begin_comment
comment|/* Define to 1 if you have the `bz2' library (-lbz2). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBBZ2 */
end_comment

begin_comment
comment|/* Define to 1 if you have the `charset' library (-lcharset). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBCHARSET */
end_comment

begin_comment
comment|/* Define to 1 if you have the `crypto' library (-lcrypto). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBCRYPTO */
end_comment

begin_comment
comment|/* Define to 1 if you have the `eay32' library (-leay32). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBEAY32 */
end_comment

begin_comment
comment|/* Define to 1 if you have the `eay64' library (-leay64). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBEAY64 */
end_comment

begin_comment
comment|/* Define to 1 if you have the `expat' library (-lexpat). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBEXPAT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `lz4' library (-llz4). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBLZ4 */
end_comment

begin_comment
comment|/* Define to 1 if you have the `lzma' library (-llzma). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBLZMA */
end_comment

begin_comment
comment|/* Define to 1 if you have the `lzmadec' library (-llzmadec). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBLZMADEC */
end_comment

begin_comment
comment|/* Define to 1 if you have the `lzo2' library (-llzo2). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBLZO2 */
end_comment

begin_comment
comment|/* Define to 1 if you have the `md' library (-lmd). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBMD */
end_comment

begin_comment
comment|/* Define to 1 if you have the `nettle' library (-lnettle). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBNETTLE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `pcre' library (-lpcre). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBPCRE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `pcreposix' library (-lpcreposix). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBPCREPOSIX */
end_comment

begin_comment
comment|/* Define to 1 if you have the `regex' library (-lregex). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBREGEX */
end_comment

begin_comment
comment|/* Define to 1 if you have the `xml2' library (-lxml2). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBXML2 */
end_comment

begin_comment
comment|/* Define to 1 if you have the<libxml/xmlreader.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LIBXML_XMLREADER_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<libxml/xmlwriter.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LIBXML_XMLWRITER_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `z' library (-lz). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBZ */
end_comment

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
comment|/* Define to 1 if you have the `link' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LINK */
end_comment

begin_comment
comment|/* Define to 1 if you have the<linux/fiemap.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_FIEMAP_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<linux/fs.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_FS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<linux/magic.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_MAGIC_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<linux/types.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_TYPES_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `listea' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LISTEA */
end_comment

begin_comment
comment|/* Define to 1 if you have the `listxattr' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LISTXATTR */
end_comment

begin_comment
comment|/* Define to 1 if you have the `llistea' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LLISTEA */
end_comment

begin_comment
comment|/* Define to 1 if you have the `llistxattr' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LLISTXATTR */
end_comment

begin_comment
comment|/* Define to 1 if you have the<localcharset.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LOCALCHARSET_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `locale_charset' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LOCALE_CHARSET */
end_comment

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
comment|/* Define to 1 if you have the `localtime_r' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LOCALTIME_R */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `long long int'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_LONG_INT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `lsetea' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LSETEA */
end_comment

begin_comment
comment|/* Define to 1 if you have the `lsetxattr' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LSETXATTR */
end_comment

begin_comment
comment|/* Define to 1 if you have the `lstat' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LSTAT */
end_comment

begin_comment
comment|/* Define to 1 if `lstat' has the bug that it succeeds when given the    zero-length file name argument. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LSTAT_EMPTY_STRING_BUG
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `lutimes' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LUTIMES */
end_comment

begin_comment
comment|/* Define to 1 if you have the<lz4hc.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LZ4HC_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<lz4.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LZ4_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<lzmadec.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LZMADEC_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<lzma.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LZMA_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<lzo/lzo1x.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LZO_LZO1X_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<lzo/lzoconf.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LZO_LZOCONF_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `mbrtowc' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MBRTOWC
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<md5.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MD5_H */
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
comment|/* Define to 1 if you have the `memset' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMSET
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mkdir' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKDIR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mkfifo' function. */
end_comment

begin_comment
comment|/* #undef HAVE_MKFIFO */
end_comment

begin_comment
comment|/* Define to 1 if you have the `mknod' function. */
end_comment

begin_comment
comment|/* #undef HAVE_MKNOD */
end_comment

begin_comment
comment|/* Define to 1 if you have the `mkstemp' function. */
end_comment

begin_comment
comment|/* #undef HAVE_MKSTEMP */
end_comment

begin_comment
comment|/* Define to 1 if you have the<ndir.h> header file, and it defines `DIR'. */
end_comment

begin_comment
comment|/* #undef HAVE_NDIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<nettle/md5.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETTLE_MD5_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<nettle/pbkdf2.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETTLE_PBKDF2_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<nettle/ripemd160.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETTLE_RIPEMD160_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<nettle/sha.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETTLE_SHA_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `nl_langinfo' function. */
end_comment

begin_comment
comment|/* #undef HAVE_NL_LANGINFO */
end_comment

begin_comment
comment|/* Define to 1 if you have the `openat' function. */
end_comment

begin_comment
comment|/* #undef HAVE_OPENAT */
end_comment

begin_comment
comment|/* Define to 1 if you have the<openssl/evp.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_OPENSSL_EVP_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<paths.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_PATHS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<pcreposix.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_PCREPOSIX_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `pipe' function. */
end_comment

begin_comment
comment|/* #undef HAVE_PIPE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `PKCS5_PBKDF2_HMAC_SHA1' function. */
end_comment

begin_comment
comment|/* #undef HAVE_PKCS5_PBKDF2_HMAC_SHA1 */
end_comment

begin_comment
comment|/* Define to 1 if you have the `poll' function. */
end_comment

begin_comment
comment|/* #undef HAVE_POLL */
end_comment

begin_comment
comment|/* Define to 1 if you have the<poll.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_POLL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `posix_spawnp' function. */
end_comment

begin_comment
comment|/* #undef HAVE_POSIX_SPAWNP */
end_comment

begin_comment
comment|/* Define to 1 if you have the<pthread.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<pwd.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_PWD_H */
end_comment

begin_comment
comment|/* Define to 1 if you have a POSIX compatible readdir_r */
end_comment

begin_define
define|#
directive|define
name|HAVE_READDIR_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `readlink' function. */
end_comment

begin_comment
comment|/* #undef HAVE_READLINK */
end_comment

begin_comment
comment|/* Define to 1 if you have the `readlinkat' function. */
end_comment

begin_comment
comment|/* #undef HAVE_READLINKAT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `readpassphrase' function. */
end_comment

begin_comment
comment|/* #undef HAVE_READPASSPHRASE */
end_comment

begin_comment
comment|/* Define to 1 if you have the<readpassphrase.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_READPASSPHRASE_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<regex.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_REGEX_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<ripemd.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_RIPEMD_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `select' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SELECT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `setenv' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SETENV */
end_comment

begin_comment
comment|/* Define to 1 if you have the `setlocale' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLOCALE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sha256.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SHA256_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sha512.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SHA512_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sha.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SHA_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `sigaction' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SIGACTION */
end_comment

begin_comment
comment|/* Define to 1 if you have the<signal.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGNAL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<spawn.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SPAWN_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `statfs' function. */
end_comment

begin_comment
comment|/* #undef HAVE_STATFS */
end_comment

begin_comment
comment|/* Define to 1 if you have the `statvfs' function. */
end_comment

begin_comment
comment|/* #undef HAVE_STATVFS */
end_comment

begin_comment
comment|/* Define to 1 if `stat' has the bug that it succeeds when given the    zero-length file name argument. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STAT_EMPTY_STRING_BUG
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdarg.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDARG_H
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
comment|/* Define to 1 if you have the `strchr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCHR
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
comment|/* Define to 1 if you have the `strerror_r' function. */
end_comment

begin_comment
comment|/* #undef HAVE_STRERROR_R */
end_comment

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
comment|/* Define to 1 if you have the `strncpy_s' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRNCPY_S
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strrchr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRRCHR
value|1
end_define

begin_comment
comment|/* Define to 1 if `f_namemax' is a member of `struct statfs'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STATFS_F_NAMEMAX */
end_comment

begin_comment
comment|/* Define to 1 if `f_iosize' is a member of `struct statvfs'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STATVFS_F_IOSIZE */
end_comment

begin_comment
comment|/* Define to 1 if `st_birthtime' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_BIRTHTIME */
end_comment

begin_comment
comment|/* Define to 1 if `st_birthtimespec.tv_nsec' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_BIRTHTIMESPEC_TV_NSEC */
end_comment

begin_comment
comment|/* Define to 1 if `st_blksize' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_BLKSIZE */
end_comment

begin_comment
comment|/* Define to 1 if `st_flags' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_FLAGS */
end_comment

begin_comment
comment|/* Define to 1 if `st_mtimespec.tv_nsec' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_MTIMESPEC_TV_NSEC */
end_comment

begin_comment
comment|/* Define to 1 if `st_mtime_n' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_MTIME_N */
end_comment

begin_comment
comment|/* Define to 1 if `st_mtime_usec' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_MTIME_USEC */
end_comment

begin_comment
comment|/* Define to 1 if `st_mtim.tv_nsec' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC */
end_comment

begin_comment
comment|/* Define to 1 if `st_umtime' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_UMTIME */
end_comment

begin_comment
comment|/* Define to 1 if `tm_gmtoff' is a member of `struct tm'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_TM_TM_GMTOFF */
end_comment

begin_comment
comment|/* Define to 1 if `__tm_gmtoff' is a member of `struct tm'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_TM___TM_GMTOFF */
end_comment

begin_comment
comment|/* Define to 1 if you have the `symlink' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SYMLINK */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/acl.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_ACL_H */
end_comment

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
comment|/* Define to 1 if you have the<sys/dir.h> header file, and it defines `DIR'.    */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/ea.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_EA_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/extattr.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_EXTATTR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/ioctl.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_IOCTL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/mkdev.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_MKDEV_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/mount.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_MOUNT_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/ndir.h> header file, and it defines `DIR'.    */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_NDIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/param.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/poll.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_POLL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/select.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_SELECT_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/statfs.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STATFS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/statvfs.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STATVFS_H */
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
comment|/* Define to 1 if you have the<sys/utime.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UTIME_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/utsname.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_UTSNAME_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/vfs.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_VFS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have<sys/wait.h> that is POSIX.1 compatible. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_WAIT_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/xattr.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_XATTR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `timegm' function. */
end_comment

begin_comment
comment|/* #undef HAVE_TIMEGM */
end_comment

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
comment|/* Define to 1 if you have the `tzset' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TZSET
value|1
end_define

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

begin_comment
comment|/* #undef HAVE_UNSETENV */
end_comment

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
comment|/* Define to 1 if the system has the type `unsigned long long int'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNSIGNED_LONG_LONG_INT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `utime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `utimensat' function. */
end_comment

begin_comment
comment|/* #undef HAVE_UTIMENSAT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `utimes' function. */
end_comment

begin_comment
comment|/* #undef HAVE_UTIMES */
end_comment

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
comment|/* Define to 1 if you have the `vfork' function. */
end_comment

begin_comment
comment|/* #undef HAVE_VFORK */
end_comment

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
comment|/* Define to 1 if you have the<wchar.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCHAR_H
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `wchar_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCHAR_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `wcrtomb' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCRTOMB
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `wcscmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCSCMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `wcscpy' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCSCPY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `wcslen' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCSLEN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `wctomb' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCTOMB
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<wctype.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCTYPE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<wincrypt.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WINCRYPT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<windows.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WINDOWS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<winioctl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WINIOCTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `wmemcmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WMEMCMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `wmemcpy' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WMEMCPY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have a working EXT2_IOC_GETFLAGS */
end_comment

begin_comment
comment|/* #undef HAVE_WORKING_EXT2_IOC_GETFLAGS */
end_comment

begin_comment
comment|/* Define to 1 if you have the<zlib.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_ZLIB_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `_ctime64_s' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE__CTIME64_S
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `_fseeki64' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE__FSEEKI64
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `_get_timezone' function. */
end_comment

begin_comment
comment|/* #undef HAVE__GET_TIMEZONE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `_localtime64_s' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE__LOCALTIME64_S
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `_mkgmtime64' function. */
end_comment

begin_comment
comment|/* #define HAVE__MKGMTIME64 1 */
end_comment

begin_comment
comment|/* Define as const if the declaration of iconv() needs const. */
end_comment

begin_comment
comment|/* #undef ICONV_CONST */
end_comment

begin_comment
comment|/* Define to 1 if `lstat' dereferences a symlink specified with a trailing    slash. */
end_comment

begin_comment
comment|/* #undef LSTAT_FOLLOWS_SLASHED_SYMLINK */
end_comment

begin_comment
comment|/* Define to the sub-directory in which libtool stores uninstalled libraries.    */
end_comment

begin_comment
comment|/* Define to 1 if `major', `minor', and `makedev' are declared in<mkdev.h>.    */
end_comment

begin_comment
comment|/* #undef MAJOR_IN_MKDEV */
end_comment

begin_comment
comment|/* Define to 1 if `major', `minor', and `makedev' are declared in<sysmacros.h>. */
end_comment

begin_comment
comment|/* #undef MAJOR_IN_SYSMACROS */
end_comment

begin_comment
comment|/* Define to 1 if PCRE_STATIC needs to be defined. */
end_comment

begin_comment
comment|/* #undef PCRE_STATIC */
end_comment

begin_comment
comment|/* The size of `wchar_t', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_WCHAR_T
value|2
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
comment|/* Define to 1 if strerror_r returns char *. */
end_comment

begin_comment
comment|/* #undef STRERROR_R_CHAR_P */
end_comment

begin_comment
comment|/* Define to 1 if you can safely include both<sys/time.h> and<time.h>. */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define to '0x0500' for Windows 2000 APIs. */
end_comment

begin_define
define|#
directive|define
name|WINVER
value|0x0500
end_define

begin_comment
comment|/* Number of bits in a file offset, on hosts where this is settable. */
end_comment

begin_define
define|#
directive|define
name|_FILE_OFFSET_BITS
value|64
end_define

begin_comment
comment|/* Define to 1 to make fseeko visible on some hosts (e.g. glibc 2.2). */
end_comment

begin_comment
comment|/* #undef _LARGEFILE_SOURCE */
end_comment

begin_comment
comment|/* Define for large files, on AIX-style hosts. */
end_comment

begin_comment
comment|/* #undef _LARGE_FILES */
end_comment

begin_comment
comment|/* Define to 1 if on MINIX. */
end_comment

begin_comment
comment|/* #undef _MINIX */
end_comment

begin_comment
comment|/* Define to 2 if the system does not provide POSIX.1 features except with    this defined. */
end_comment

begin_comment
comment|/* #undef _POSIX_1_SOURCE */
end_comment

begin_comment
comment|/* Define to 1 if you need to in order for `stat' and other things to work. */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

begin_comment
comment|/* Define for Solaris 2.5.1 so the uint32_t typedef from<sys/synch.h>,<pthread.h>, or<semaphore.h> is not used. If the typedef were allowed, the    #define below would cause a syntax error. */
end_comment

begin_comment
comment|/* #undef _UINT32_T */
end_comment

begin_comment
comment|/* Define for Solaris 2.5.1 so the uint64_t typedef from<sys/synch.h>,<pthread.h>, or<semaphore.h> is not used. If the typedef were allowed, the    #define below would cause a syntax error. */
end_comment

begin_comment
comment|/* #undef _UINT64_T */
end_comment

begin_comment
comment|/* Define for Solaris 2.5.1 so the uint8_t typedef from<sys/synch.h>,<pthread.h>, or<semaphore.h> is not used. If the typedef were allowed, the    #define below would cause a syntax error. */
end_comment

begin_comment
comment|/* #undef _UINT8_T */
end_comment

begin_comment
comment|/* Define to '0x0500' for Windows 2000 APIs. */
end_comment

begin_define
define|#
directive|define
name|_WIN32_WINNT
value|0x0500
end_define

begin_comment
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to match typeof st_gid field of struct stat if<sys/types.h> doesn't    define. */
end_comment

begin_define
define|#
directive|define
name|gid_t
value|short
end_define

begin_comment
comment|/* Define to `unsigned long' if<sys/types.h> does not define. */
end_comment

begin_define
define|#
directive|define
name|id_t
value|unsigned long
end_define

begin_comment
comment|/* Define to the type of a signed integer type of width exactly 16 bits if    such a type exists and the standard includes do not define it. */
end_comment

begin_comment
comment|/* #undef int16_t */
end_comment

begin_comment
comment|/* Define to the type of a signed integer type of width exactly 32 bits if    such a type exists and the standard includes do not define it. */
end_comment

begin_comment
comment|/* #undef int32_t */
end_comment

begin_comment
comment|/* Define to the type of a signed integer type of width exactly 64 bits if    such a type exists and the standard includes do not define it. */
end_comment

begin_comment
comment|/* #undef int64_t */
end_comment

begin_comment
comment|/* Define to the widest signed integer type if<stdint.h> and<inttypes.h> do    not define. */
end_comment

begin_comment
comment|/* #undef intmax_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef mode_t */
end_comment

begin_comment
comment|/* Define to `long long' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef off_t */
end_comment

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* Define to match typeof st_uid field of struct stat if<sys/types.h> doesn't    define. */
end_comment

begin_define
define|#
directive|define
name|uid_t
value|short
end_define

begin_comment
comment|/* Define to the type of an unsigned integer type of width exactly 16 bits if    such a type exists and the standard includes do not define it. */
end_comment

begin_comment
comment|/* #undef uint16_t */
end_comment

begin_comment
comment|/* Define to the type of an unsigned integer type of width exactly 32 bits if    such a type exists and the standard includes do not define it. */
end_comment

begin_comment
comment|/* #undef uint32_t */
end_comment

begin_comment
comment|/* Define to the type of an unsigned integer type of width exactly 64 bits if    such a type exists and the standard includes do not define it. */
end_comment

begin_comment
comment|/* #undef uint64_t */
end_comment

begin_comment
comment|/* Define to the type of an unsigned integer type of width exactly 8 bits if    such a type exists and the standard includes do not define it. */
end_comment

begin_comment
comment|/* #undef uint8_t */
end_comment

begin_comment
comment|/* Define to the widest unsigned integer type if<stdint.h> and<inttypes.h>    do not define. */
end_comment

begin_comment
comment|/* #undef uintmax_t */
end_comment

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef uintptr_t */
end_comment

end_unit

