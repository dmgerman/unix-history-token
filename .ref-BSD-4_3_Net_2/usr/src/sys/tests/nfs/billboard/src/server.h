begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  Number of hash buckets, best performance if 2*number entries. */
end_comment

begin_define
define|#
directive|define
name|BB_MAX_HASH
value|(2 * BB_MAX_IMP)
end_define

begin_define
define|#
directive|define
name|BB_HASH_TABLE_FULL
value|(-1)
end_define

begin_define
define|#
directive|define
name|BB_HASH_ID_NOT_FOUND
value|(-2)
end_define

begin_comment
comment|/* **  Defines for the names of the data files. */
end_comment

begin_define
define|#
directive|define
name|BB_CODATA_FILE
value|"bb_data.company"
end_define

begin_define
define|#
directive|define
name|BB_PASSWD_FILE
value|"bb_data.passwd"
end_define

begin_define
define|#
directive|define
name|BB_PHASE_FILE
value|"bb_data.phases"
end_define

begin_define
define|#
directive|define
name|BB_BOARD_FILE
value|"bb_data.board"
end_define

begin_comment
comment|/* **  Defines for the company data file. */
end_comment

begin_define
define|#
directive|define
name|BB_COMMENT_DESIGNATOR
value|'#'
end_define

begin_define
define|#
directive|define
name|BB_IP_DESIGNATOR
value|'P'
end_define

begin_define
define|#
directive|define
name|BB_CO_DESIGNATOR
value|'C'
end_define

begin_define
define|#
directive|define
name|BB_IMP_DESIGNATOR
value|'I'
end_define

begin_define
define|#
directive|define
name|BB_ID_DESIGNATOR
value|'D'
end_define

begin_define
define|#
directive|define
name|BB_BOOTH_DESIGNATOR
value|'B'
end_define

begin_define
define|#
directive|define
name|BB_FLAGS_DESIGNATOR
value|'F'
end_define

begin_define
define|#
directive|define
name|BB_END_DESIGNATOR
value|'E'
end_define

begin_define
define|#
directive|define
name|BB_DES_CHAR
value|1
end_define

begin_comment
comment|/* Unique of all DESIGN.*/
end_comment

begin_define
define|#
directive|define
name|BB_DES_START
value|3
end_define

begin_comment
comment|/* Start of data in line*/
end_comment

begin_define
define|#
directive|define
name|BB_IP_SEPARATOR
value|" "
end_define

begin_define
define|#
directive|define
name|BB_IP_ADDR_LEN
value|16
end_define

begin_define
define|#
directive|define
name|BB_MAX_IP
value|(2*BB_MAX_IMP)
end_define

begin_define
define|#
directive|define
name|BB_BOARD_UNSET
value|0
end_define

begin_define
define|#
directive|define
name|BB_BOARD_SET
value|1
end_define

begin_define
define|#
directive|define
name|BB_SUN_SERVER
value|"SUN"
end_define

begin_define
define|#
directive|define
name|BB_SUN_PHASE
value|1
end_define

begin_comment
comment|/* **  This is a bucket of the hash table used to hash the implementation **  name to an index. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|id_ptr
decl_stmt|;
comment|/* ptr to co_data.identifier */
name|short
name|index
decl_stmt|;
comment|/* The index assigned this implementation*/
block|}
name|BB_bucket
typedef|;
end_typedef

begin_comment
comment|/* **  The hash table structure is an array of buckets.  We are not worried **  about the space limitations for this project. */
end_comment

begin_typedef
typedef|typedef
name|BB_bucket
name|BB_hash
index|[
name|BB_MAX_HASH
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|company
index|[
name|BB_COMPANY_NAME_LEN
index|]
decl_stmt|;
name|char
name|imp
index|[
name|BB_IMP_NAME_LEN
index|]
decl_stmt|;
name|BB_id
name|id
decl_stmt|;
comment|/* Assigned reference name.	*/
name|int
name|booth
decl_stmt|;
name|short
name|flags
decl_stmt|;
comment|/* BB_SERVER, BB_CLIENT, BB_NONE*/
name|short
name|ip_cnt
decl_stmt|;
comment|/* # of internet addresses	*/
name|short
name|ip_idx
decl_stmt|;
comment|/* index to ip table.		*/
block|}
name|BB_co_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|BB_ip
index|[
name|BB_IP_ADDR_LEN
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uchar
name|BB_phase
typedef|;
end_typedef

begin_comment
comment|/* BB_PHASE1, BB_PHASE2 */
end_comment

end_unit

