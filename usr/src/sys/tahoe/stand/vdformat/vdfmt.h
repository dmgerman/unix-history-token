begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vdfmt.h	1.1	86/07/05	*/
end_comment

begin_comment
comment|/* ** */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|"tahoe/mtpr.h"
end_include

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"inode.h"
end_include

begin_include
include|#
directive|include
file|"fs.h"
end_include

begin_include
include|#
directive|include
file|"tahoevba/vbaparam.h"
end_include

begin_include
include|#
directive|include
file|"tahoevba/vdreg.h"
end_include

begin_include
include|#
directive|include
file|"tahoe/cp.h"
end_include

begin_decl_stmt
specifier|extern
name|struct
name|cpdcb_i
name|cpin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Poll console and return 1 if input is present.  */
end_comment

begin_define
define|#
directive|define
name|input
parameter_list|()
define|\
value|(uncache(&cpin.cp_hdr.cp_unit), (cpin.cp_hdr.cp_unit&CPDONE))
end_define

begin_comment
comment|/* Configuration parameters */
end_comment

begin_define
define|#
directive|define
name|MAXCTLR
value|8
end_define

begin_comment
comment|/* Maximum # of controllers */
end_comment

begin_define
define|#
directive|define
name|MAXDRIVE
value|16
end_define

begin_comment
comment|/* Max drives per controller */
end_comment

begin_define
define|#
directive|define
name|NUMMAP
value|1
end_define

begin_comment
comment|/* # Cyls in bad sector map */
end_comment

begin_define
define|#
directive|define
name|NUMMNT
value|1
end_define

begin_comment
comment|/* # cyls for diagnostics */
end_comment

begin_define
define|#
directive|define
name|NUMREL
value|3
end_define

begin_comment
comment|/* # Cyls in relocation area */
end_comment

begin_define
define|#
directive|define
name|NUMSYS
value|(NUMREL+NUMMNT+NUMMAP)
end_define

begin_comment
comment|/* Total cyls used by system */
end_comment

begin_define
define|#
directive|define
name|MAXTRKS
value|24
end_define

begin_define
define|#
directive|define
name|MAXSECS_PER_TRK
value|64
end_define

begin_define
define|#
directive|define
name|MAXERR
value|1000
end_define

begin_define
define|#
directive|define
name|SECSIZ
value|512
end_define

begin_define
define|#
directive|define
name|TRKSIZ
value|((SECSIZ/sizeof(long)) * MAXSECS_PER_TRK)
end_define

begin_define
define|#
directive|define
name|bytes_trk
value|(CURRENT->vc_nsec * SECSIZ)
end_define

begin_define
define|#
directive|define
name|HARD_ERROR
value|(DRVNRDY | INVDADR | DNEMEM | PARERR | OPABRT | \ 			 WPTERR | DSEEKERR | NOTCYLERR)
end_define

begin_define
define|#
directive|define
name|DATA_ERROR
value|(CTLRERR | UCDATERR | DCOMPERR | DSERLY | DSLATE | \ 			 TOPLUS | TOMNUS | CPDCRT | \ 			 HRDERR | SFTERR)
end_define

begin_define
define|#
directive|define
name|HEADER_ERROR
value|(HCRCERR | HCMPERR)
end_define

begin_define
define|#
directive|define
name|NRM
value|(short)0
end_define

begin_define
define|#
directive|define
name|BAD
value|(short)VDUF
end_define

begin_define
define|#
directive|define
name|WPT
value|(short)(NRM | VDWPT)
end_define

begin_define
define|#
directive|define
name|RELOC_SECTOR
value|(short)(VDALT)
end_define

begin_define
define|#
directive|define
name|ALT_SECTOR
value|(short)(VDALT)
end_define

begin_comment
comment|/* New types used by VDFORMAT */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|false
block|,
name|true
block|}
name|boolean
typedef|;
end_typedef

begin_comment
comment|/* Standard boolean expression */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|u_false
block|,
name|u_true
block|,
name|u_unknown
block|}
name|uncertain
typedef|;
end_typedef

begin_comment
comment|/* Free bad block allocation bit map */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|free_error
decl_stmt|;
enum|enum
block|{
name|ALLOCATED
block|,
name|NOTALLOCATED
block|}
name|free_status
enum|;
block|}
name|fmt_free
typedef|;
end_typedef

begin_comment
comment|/* Type of relocation that took place */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SINGLE_SECTOR
block|,
name|FULL_TRACK
block|}
name|rel_type
typedef|;
end_typedef

begin_comment
comment|/* Error table format */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dskadr
name|err_adr
decl_stmt|;
name|long
name|err_stat
decl_stmt|;
block|}
name|fmt_err
typedef|;
end_typedef

begin_comment
comment|/* utilities */
end_comment

begin_decl_stmt
name|int
name|blkcopy
argument_list|()
decl_stmt|,
name|blkzero
argument_list|()
decl_stmt|,
name|to_sector
argument_list|()
decl_stmt|,
name|to_track
argument_list|()
decl_stmt|,
name|data_ok
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|blkcmp
argument_list|()
decl_stmt|,
name|get_yes_no
argument_list|()
decl_stmt|,
name|is_in_map
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|is_formatted
argument_list|()
decl_stmt|,
name|read_bad_sector_map
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dskadr
modifier|*
name|from_sector
argument_list|()
decl_stmt|,
modifier|*
name|from_track
argument_list|()
decl_stmt|,
modifier|*
name|from_unix
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dskadr
name|is_relocated
argument_list|()
decl_stmt|,
modifier|*
name|new_location
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Operation table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|format
argument_list|()
decl_stmt|,
name|verify
argument_list|()
decl_stmt|,
name|relocate
argument_list|()
decl_stmt|,
name|info
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|correct
argument_list|()
decl_stmt|,
name|profile
argument_list|()
decl_stmt|,
name|exercise
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUMOPS
value|7
end_define

begin_comment
comment|/* operation bit mask values (must match order in operations table) */
end_comment

begin_define
define|#
directive|define
name|FORMAT_OP
value|0x01
end_define

begin_comment
comment|/* Format operation bit */
end_comment

begin_define
define|#
directive|define
name|VERIFY_OP
value|0x02
end_define

begin_comment
comment|/* Verify operation bit */
end_comment

begin_define
define|#
directive|define
name|RELOCATE_OP
value|0x04
end_define

begin_comment
comment|/* Relocate operation bit */
end_comment

begin_define
define|#
directive|define
name|INFO_OP
value|0x08
end_define

begin_comment
comment|/* Info operation bit */
end_comment

begin_define
define|#
directive|define
name|CORRECT_OP
value|0x10
end_define

begin_comment
comment|/* Correct operation bit */
end_comment

begin_define
define|#
directive|define
name|PROFILE_OP
value|0x20
end_define

begin_comment
comment|/* Profile operation bit */
end_comment

begin_define
define|#
directive|define
name|EXERCISE_OP
value|0x40
end_define

begin_comment
comment|/* Exercise operation bit */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
function_decl|(
modifier|*
name|routine
function_decl|)
parameter_list|()
function_decl|;
name|char
modifier|*
name|op_name
decl_stmt|;
name|char
modifier|*
name|op_action
decl_stmt|;
block|}
name|op_tbl
typedef|;
end_typedef

begin_decl_stmt
name|op_tbl
name|operations
index|[
name|NUMOPS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Operation table type and definitions */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|op
decl_stmt|;
name|int
name|numpat
decl_stmt|;
block|}
name|op_spec
typedef|;
end_typedef

begin_decl_stmt
name|op_spec
name|ops_to_do
index|[
name|MAXCTLR
index|]
index|[
name|MAXDRIVE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Contains all the current parameters */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|formatted
block|,
name|half_formatted
block|,
name|unformatted
block|,
name|unknown
block|}
name|drv_stat
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|fmt
block|,
name|vfy
block|,
name|rel
block|,
name|cor
block|,
name|inf
block|,
name|cmd
block|,
name|exec
block|,
name|prof
block|}
name|state
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|sub_chk
block|,
name|sub_rcvr
block|,
name|sub_stat
block|,
name|sub_rel
block|,
name|sub_vfy
block|,
name|sub_fmt
block|,
name|sub_sk
block|}
name|substate
typedef|;
end_typedef

begin_comment
comment|/* Different environments for setjumps */
end_comment

begin_decl_stmt
name|jmp_buf
name|reset_environ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use when reset is issued */
end_comment

begin_decl_stmt
name|jmp_buf
name|quit_environ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use when you want to quit what your doing */
end_comment

begin_decl_stmt
name|jmp_buf
name|abort_environ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use when nothing can be done to recover */
end_comment

begin_comment
comment|/* Flaw map definitions and storage */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|bs_cyl
decl_stmt|;
comment|/* Cylinder position of flaw */
name|short
name|bs_trk
decl_stmt|;
comment|/* Track position of flaw */
name|long
name|bs_offset
decl_stmt|;
comment|/* (byte) Position of flaw on track */
name|long
name|bs_length
decl_stmt|;
comment|/* Length (in bits) of flaw */
name|dskadr
name|bs_alt
decl_stmt|;
comment|/* Addr of alt sector (all 0 if none) */
enum|enum
block|{
name|flaw_map
block|,
name|scanning
block|,
name|operator
block|}
name|bs_how
enum|;
comment|/* How it was found */
block|}
name|bs_entry
typedef|;
end_typedef

begin_struct
struct|struct
block|{
name|int
name|controller
decl_stmt|;
name|int
name|drive
decl_stmt|;
name|state
name|state
decl_stmt|;
name|substate
name|substate
decl_stmt|;
name|int
name|error
decl_stmt|;
name|dskadr
name|daddr
decl_stmt|;
block|}
name|cur
struct|;
end_struct

begin_comment
comment|/* Controller specific information */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uncertain
name|alive
decl_stmt|;
name|cdr
modifier|*
name|addr
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|type
decl_stmt|;
name|fmt_err
function_decl|(
modifier|*
name|decode_pos
function_decl|)
parameter_list|()
function_decl|;
name|bs_entry
function_decl|(
modifier|*
name|code_pos
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|cylinder_skew
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|track_skew
function_decl|)
parameter_list|()
function_decl|;
block|}
name|ctlr_info
typedef|;
end_typedef

begin_decl_stmt
name|ctlr_info
name|c_info
index|[
name|MAXCTLR
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* drive specific information */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uncertain
name|alive
decl_stmt|;
name|int
name|id
decl_stmt|;
name|struct
name|vdconfig
modifier|*
name|info
decl_stmt|;
name|int
name|trk_size
decl_stmt|;
name|int
name|num_slip
decl_stmt|;
name|int
name|track_skew
decl_stmt|;
name|drv_stat
name|condition
decl_stmt|;
block|}
name|drive_info
typedef|;
end_typedef

begin_decl_stmt
name|drive_info
name|d_info
index|[
name|MAXCTLR
index|]
index|[
name|MAXDRIVE
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|D_INFO
value|d_info[cur.controller][cur.drive]
end_define

begin_define
define|#
directive|define
name|C_INFO
value|c_info[cur.controller]
end_define

begin_define
define|#
directive|define
name|CURRENT
value|D_INFO.info
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|bs_id
decl_stmt|;
comment|/* Pack id */
name|unsigned
name|int
name|bs_count
decl_stmt|;
comment|/* number of known bad sectors */
name|unsigned
name|int
name|bs_max
decl_stmt|;
comment|/* Maximum allowable bad sectors */
name|bs_entry
name|list
index|[
literal|1
index|]
decl_stmt|;
block|}
name|bs_map
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_FLAWS
value|(((TRKSIZ*sizeof(long))-sizeof(bs_map))/sizeof(bs_entry))
end_define

begin_decl_stmt
name|long
name|bs_map_space
index|[
name|TRKSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bs_map
modifier|*
name|bad_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|kill_processes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|num_controllers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pattern buffers and the sort */
end_comment

begin_decl_stmt
name|fmt_free
name|free_tbl
index|[
name|NUMREL
operator|*
name|MAXTRKS
index|]
index|[
name|MAXSECS_PER_TRK
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|fmt_mdcb
name|mdcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Master device control block */
end_comment

begin_decl_stmt
name|fmt_dcb
name|dcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Device control blocks */
end_comment

begin_decl_stmt
name|long
name|pattern_0
index|[
name|TRKSIZ
index|]
decl_stmt|,
name|pattern_1
index|[
name|TRKSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|pattern_2
index|[
name|TRKSIZ
index|]
decl_stmt|,
name|pattern_3
index|[
name|TRKSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|pattern_4
index|[
name|TRKSIZ
index|]
decl_stmt|,
name|pattern_5
index|[
name|TRKSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|pattern_6
index|[
name|TRKSIZ
index|]
decl_stmt|,
name|pattern_7
index|[
name|TRKSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|pattern_8
index|[
name|TRKSIZ
index|]
decl_stmt|,
name|pattern_9
index|[
name|TRKSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|pattern_10
index|[
name|TRKSIZ
index|]
decl_stmt|,
name|pattern_11
index|[
name|TRKSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|pattern_12
index|[
name|TRKSIZ
index|]
decl_stmt|,
name|pattern_13
index|[
name|TRKSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|pattern_14
index|[
name|TRKSIZ
index|]
decl_stmt|,
name|pattern_15
index|[
name|TRKSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Will be filled in at boot time with pointers to above patterns */
end_comment

begin_decl_stmt
name|long
modifier|*
name|pattern_address
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Double buffer for scanning existing file systems and general scratch */
end_comment

begin_decl_stmt
name|long
name|scratch
index|[
name|TRKSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|save
index|[
name|TRKSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/*  * Flaw map stuff   */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|flaw_sync
decl_stmt|;
name|short
name|flaw_cyl
decl_stmt|;
name|char
name|flaw_trk
decl_stmt|;
name|char
name|flaw_sec
decl_stmt|;
struct|struct
block|{
name|short
name|flaw_offset
decl_stmt|;
name|short
name|flaw_length
decl_stmt|;
block|}
name|flaw_pos
index|[
literal|4
index|]
struct|;
name|char
name|flaw_status
decl_stmt|;
name|char
name|flaw_junk
index|[
literal|1024
index|]
decl_stmt|;
comment|/* Fill up 518 byte block */
block|}
name|flaw
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|smde_sync
decl_stmt|;
name|unsigned
name|adr_cyl
range|:
literal|12
decl_stmt|;
name|unsigned
name|adr_trk
range|:
literal|8
decl_stmt|;
name|unsigned
name|adr_sec
range|:
literal|8
decl_stmt|;
name|unsigned
name|sec_flgs
range|:
literal|4
decl_stmt|;
name|unsigned
name|alt_cyl
range|:
literal|12
decl_stmt|;
name|unsigned
name|alt_trk
range|:
literal|8
decl_stmt|;
name|unsigned
name|alt_sec
range|:
literal|8
decl_stmt|;
name|char
name|smde_junk
index|[
literal|1024
index|]
decl_stmt|;
block|}
name|smde_hdr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CDCSYNC
value|0x1919
end_define

begin_define
define|#
directive|define
name|SMDSYNC
value|0x0019
end_define

begin_define
define|#
directive|define
name|SMDESYNC
value|0x0009
end_define

begin_define
define|#
directive|define
name|SMDE1SYNC
value|0x000d
end_define

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/*  * Disk drive geometry definition.  */
end_comment

begin_struct
struct|struct
name|geometry
block|{
name|u_short
name|g_nsec
decl_stmt|;
comment|/* sectors/track */
name|u_short
name|g_ntrak
decl_stmt|;
comment|/* tracks/cylinder */
name|u_int
name|g_ncyl
decl_stmt|;
comment|/* cylinders/drive */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flaw testing patterns.  */
end_comment

begin_struct
struct|struct
name|flawpat
block|{
name|u_int
name|fp_pat
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Disk drive configuration information.  */
end_comment

begin_struct
struct|struct
name|vdconfig
block|{
name|char
modifier|*
name|vc_name
decl_stmt|;
comment|/* drive name for selection */
name|struct
name|geometry
name|vc_geometry
decl_stmt|;
comment|/* disk geometry */
define|#
directive|define
name|vc_nsec
value|vc_geometry.g_nsec
define|#
directive|define
name|vc_ntrak
value|vc_geometry.g_ntrak
define|#
directive|define
name|vc_ncyl
value|vc_geometry.g_ncyl
name|int
name|vc_nslip
decl_stmt|;
comment|/* # of slip sectors */
name|int
name|vc_rpm
decl_stmt|;
comment|/* revolutions/minute */
name|int
name|vc_traksize
decl_stmt|;
comment|/* bits/track for flaw map interp */
name|struct
name|flawpat
modifier|*
name|vc_pat
decl_stmt|;
comment|/* flaw testing patterns */
name|char
modifier|*
name|vc_type
decl_stmt|;
comment|/* informative description */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|vdconfig
name|vdconfig
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ndrives
decl_stmt|;
end_decl_stmt

end_unit

