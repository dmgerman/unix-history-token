begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bboards.h - definition of a BBoard structure */
end_comment

begin_define
define|#
directive|define
name|BBOARDS
value|"bboards"
end_define

begin_comment
comment|/* name in /etc/passwd */
end_comment

begin_define
define|#
directive|define
name|BBDB
value|"BBoards"
end_define

begin_comment
comment|/* file in BBOARDS' home directory */
end_comment

begin_define
define|#
directive|define
name|BBMODE
value|0644
end_define

begin_comment
comment|/* default BBoards mode */
end_comment

begin_define
define|#
directive|define
name|DISTADR
value|"dist-"
end_define

begin_comment
comment|/* prefix for distribution addresses */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|POP
end_ifdef

begin_define
define|#
directive|define
name|POPUID
value|"pop"
end_define

begin_comment
comment|/* name in /etc/passwd */
end_comment

begin_define
define|#
directive|define
name|POPDB
value|"POP"
end_define

begin_comment
comment|/* file in POPUID's home directory */
end_comment

begin_define
define|#
directive|define
name|POMODE
value|0600
end_define

begin_comment
comment|/* default POP subscriber maildrop mode */
end_comment

begin_endif
endif|#
directive|endif
endif|POP
end_endif

begin_struct
struct|struct
name|bboard
block|{
name|char
modifier|*
name|bb_name
decl_stmt|;
comment|/* name of the bboard */
name|char
modifier|*
modifier|*
name|bb_aka
decl_stmt|;
comment|/* aliases for the bboards */
name|char
modifier|*
name|bb_file
decl_stmt|;
comment|/* file it resides in */
name|char
modifier|*
name|bb_archive
decl_stmt|;
comment|/* file where archives reside */
name|char
modifier|*
name|bb_info
decl_stmt|;
comment|/* file where maxima resides */
name|char
modifier|*
name|bb_map
decl_stmt|;
comment|/* file where binary map resides */
name|char
modifier|*
name|bb_passwd
decl_stmt|;
comment|/* password for it */
name|char
modifier|*
modifier|*
name|bb_leader
decl_stmt|;
comment|/* list of local leaders */
name|char
modifier|*
name|bb_addr
decl_stmt|;
comment|/* network address */
name|char
modifier|*
name|bb_request
decl_stmt|;
comment|/* network address for requests */
name|char
modifier|*
name|bb_relay
decl_stmt|;
comment|/* host acting as relay in local domain */
name|char
modifier|*
modifier|*
name|bb_dist
decl_stmt|;
comment|/* distribution list */
name|unsigned
name|int
name|bb_flags
decl_stmt|;
comment|/* various flags */
define|#
directive|define
name|BB_NULL
value|0x0000
define|#
directive|define
name|BB_ARCH
value|0x0007
comment|/* archive policy */
define|#
directive|define
name|BB_ASAV
value|0x0001
comment|/*   save in archives/ directory */
define|#
directive|define
name|BB_AREM
value|0x0002
comment|/*   remove without saving */
define|#
directive|define
name|BB_INVIS
value|0x0010
comment|/* invisible to bbc */
define|#
directive|define
name|BB_REMOTE
value|0x0020
comment|/* remote to bbc */
define|#
directive|define
name|BB_SEEN
value|0x0040
comment|/* seen by bbc */
define|#
directive|define
name|BBITS
value|"\020\01ARCHIVE\02REMOVE\05INVIS\06REMOTE\07SEEN"
union|union
block|{
comment|/* unassigned */
name|unsigned
name|int
name|un_count
decl_stmt|;
name|long
name|un_mtime
decl_stmt|;
block|}
name|bb_un
union|;
define|#
directive|define
name|bb_count
value|bb_un.un_count
define|#
directive|define
name|bb_mtime
value|bb_un.un_mtime
name|unsigned
name|int
name|bb_maxima
decl_stmt|;
comment|/* highest BBoard-Id in it */
name|char
modifier|*
name|bb_date
decl_stmt|;
comment|/* date that maxima was written */
name|struct
name|bboard
modifier|*
name|bb_next
decl_stmt|;
comment|/* unassigned */
name|struct
name|bboard
modifier|*
name|bb_link
decl_stmt|;
comment|/* unassigned */
name|struct
name|bboard
modifier|*
name|bb_chain
decl_stmt|;
comment|/* unassigned */
block|}
struct|;
end_struct

begin_comment
comment|/* flags for setbbent () */
end_comment

begin_define
define|#
directive|define
name|SB_NULL
value|0x0000
end_define

begin_define
define|#
directive|define
name|SB_STAY
value|0x0001
end_define

begin_comment
comment|/*   stay open between calls */
end_comment

begin_define
define|#
directive|define
name|SB_FAST
value|0x0002
end_define

begin_comment
comment|/*   fast parse of file */
end_comment

begin_function_decl
name|void
name|make_lower
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|setbbent
argument_list|()
decl_stmt|,
name|endbbent
argument_list|()
decl_stmt|,
name|setbbfile
argument_list|()
decl_stmt|,
name|setbbinfo
argument_list|()
decl_stmt|,
name|setpwinfo
argument_list|()
decl_stmt|,
name|ldrbb
argument_list|()
decl_stmt|,
name|ldrchk
argument_list|()
decl_stmt|,
name|getbbdist
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|long
name|getbbtime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getbberr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|bboard
modifier|*
name|getbbent
argument_list|()
decl_stmt|,
modifier|*
name|getbbnam
argument_list|()
decl_stmt|,
modifier|*
name|getbbaka
argument_list|()
decl_stmt|,
modifier|*
name|getbbcpy
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

