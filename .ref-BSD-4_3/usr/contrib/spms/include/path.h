begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Pathname definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Buffer sizes  */
end_comment

begin_define
define|#
directive|define
name|ALIASSIZE
value|30
end_define

begin_comment
comment|/* project directory alias size */
end_comment

begin_define
define|#
directive|define
name|TYPESIZE
value|30
end_define

begin_comment
comment|/* project directory type label size */
end_comment

begin_define
define|#
directive|define
name|DIRDESCSIZE
value|128
end_define

begin_comment
comment|/* project directory description size */
end_comment

begin_define
define|#
directive|define
name|P_BUFSIZE
value|1024
end_define

begin_comment
comment|/* pathname buffer size */
end_comment

begin_define
define|#
directive|define
name|PATHSIZE
value|256
end_define

begin_comment
comment|/* maximum pathname length */
end_comment

begin_define
define|#
directive|define
name|PPATHSIZE
value|128
end_define

begin_comment
comment|/* maximum project pathname length */
end_comment

begin_define
define|#
directive|define
name|TYPBUFSIZE
value|256
end_define

begin_comment
comment|/* directory type labels buffer */
end_comment

begin_comment
comment|/*   * Nomenclature (WARNING: Check definition usage BEFORE changing)  */
end_comment

begin_define
define|#
directive|define
name|_CDIRC
value|'.'
end_define

begin_comment
comment|/* current directory character */
end_comment

begin_define
define|#
directive|define
name|_HDIRC
value|'~'
end_define

begin_comment
comment|/* home directory character */
end_comment

begin_define
define|#
directive|define
name|_PDIRC
value|'^'
end_define

begin_comment
comment|/* project root directory character */
end_comment

begin_define
define|#
directive|define
name|_PDTSC
value|'/'
end_define

begin_comment
comment|/* project dir type labels sep char */
end_comment

begin_define
define|#
directive|define
name|_PPSC
value|'^'
end_define

begin_comment
comment|/* project path separator character */
end_comment

begin_define
define|#
directive|define
name|_PSC
value|'/'
end_define

begin_comment
comment|/* pathname separator character */
end_comment

begin_define
define|#
directive|define
name|_RDIRC
value|'/'
end_define

begin_comment
comment|/* root directory character */
end_comment

begin_define
define|#
directive|define
name|CURDIR
value|"."
end_define

begin_comment
comment|/* current directory */
end_comment

begin_define
define|#
directive|define
name|PARENTDIR
value|".."
end_define

begin_comment
comment|/* parent directory */
end_comment

begin_define
define|#
directive|define
name|PATHSEP
value|"/"
end_define

begin_comment
comment|/* pathname separator */
end_comment

begin_define
define|#
directive|define
name|PPATHSEP
value|"^"
end_define

begin_comment
comment|/* project pathname separator */
end_comment

begin_define
define|#
directive|define
name|ROOTDIR
value|"/"
end_define

begin_comment
comment|/* root directory */
end_comment

begin_define
define|#
directive|define
name|ROOTPROJECT
value|"^"
end_define

begin_comment
comment|/* root project */
end_comment

begin_define
define|#
directive|define
name|USERPROJECT
value|"~"
end_define

begin_comment
comment|/* user's root project */
end_comment

begin_comment
comment|/*  * Pathname types  */
end_comment

begin_define
define|#
directive|define
name|P_IFMT
value|0xf0000
end_define

begin_comment
comment|/* project pathname mask */
end_comment

begin_define
define|#
directive|define
name|P_IFNEW
value|0x00000
end_define

begin_comment
comment|/* new directory or file */
end_comment

begin_define
define|#
directive|define
name|P_IFREG
value|0x10000
end_define

begin_comment
comment|/* regular directory or file */
end_comment

begin_define
define|#
directive|define
name|P_IFHOME
value|0x20000
end_define

begin_comment
comment|/* root project root directory */
end_comment

begin_define
define|#
directive|define
name|P_IFPDIR
value|0x30000
end_define

begin_comment
comment|/* project directory */
end_comment

begin_define
define|#
directive|define
name|P_IFPROOT
value|0x40000
end_define

begin_comment
comment|/* project root directory */
end_comment

begin_comment
comment|/*  * Pathname struct  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_path
block|{
name|unsigned
name|long
name|p_mode
decl_stmt|;
comment|/* type of pathname */
name|char
modifier|*
name|p_alias
decl_stmt|;
comment|/* pathname alias */
name|char
modifier|*
name|p_path
decl_stmt|;
comment|/* pathname */
name|char
modifier|*
name|p_type
decl_stmt|;
comment|/* project directory type labels */
name|char
modifier|*
name|p_desc
decl_stmt|;
comment|/* project directory description */
name|char
name|p_buf
index|[
name|P_BUFSIZE
index|]
decl_stmt|;
comment|/* pathname buffer */
name|char
name|p_project
index|[
name|PATHSIZE
index|]
decl_stmt|;
comment|/* pathname's project */
block|}
name|PATH
typedef|;
end_typedef

end_unit

