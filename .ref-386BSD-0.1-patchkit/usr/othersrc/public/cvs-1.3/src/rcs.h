begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)rcs.h 1.14 92/03/31	 */
end_comment

begin_comment
comment|/*  * Copyright (c) 1992, Brian Berliner and Jeff Polk  * Copyright (c) 1989-1992, Brian Berliner  *   * You may distribute under the terms of the GNU General Public License as  * specified in the README file that comes with the CVS 1.3 kit.  *   * RCS source control definitions needed by rcs.c and friends  */
end_comment

begin_define
define|#
directive|define
name|RCS
value|"rcs"
end_define

begin_define
define|#
directive|define
name|RCS_CI
value|"ci"
end_define

begin_define
define|#
directive|define
name|RCS_CO
value|"co"
end_define

begin_define
define|#
directive|define
name|RCS_RLOG
value|"rlog"
end_define

begin_define
define|#
directive|define
name|RCS_DIFF
value|"rcsdiff"
end_define

begin_define
define|#
directive|define
name|RCS_MERGE
value|"merge"
end_define

begin_define
define|#
directive|define
name|RCS_RCSMERGE
value|"rcsmerge"
end_define

begin_define
define|#
directive|define
name|RCS_MERGE_PAT
value|"^>>>>>>> "
end_define

begin_comment
comment|/* runs "grep" with this pattern */
end_comment

begin_define
define|#
directive|define
name|RCSEXT
value|",v"
end_define

begin_define
define|#
directive|define
name|RCSHEAD
value|"head"
end_define

begin_define
define|#
directive|define
name|RCSBRANCH
value|"branch"
end_define

begin_define
define|#
directive|define
name|RCSSYMBOLS
value|"symbols"
end_define

begin_define
define|#
directive|define
name|RCSDATE
value|"date"
end_define

begin_define
define|#
directive|define
name|RCSDESC
value|"desc"
end_define

begin_define
define|#
directive|define
name|DATEFORM
value|"%02d.%02d.%02d.%02d.%02d.%02d"
end_define

begin_define
define|#
directive|define
name|SDATEFORM
value|"%d.%d.%d.%d.%d.%d"
end_define

begin_comment
comment|/*  * Opaque structure definitions used by RCS specific lookup routines  */
end_comment

begin_define
define|#
directive|define
name|VALID
value|0x1
end_define

begin_comment
comment|/* flags field contains valid data */
end_comment

begin_define
define|#
directive|define
name|INATTIC
value|0x2
end_define

begin_comment
comment|/* RCS file is located in the Attic */
end_comment

begin_struct
struct|struct
name|rcsnode
block|{
name|int
name|refcount
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|char
modifier|*
name|path
decl_stmt|;
name|char
modifier|*
name|head
decl_stmt|;
name|char
modifier|*
name|branch
decl_stmt|;
name|List
modifier|*
name|symbols
decl_stmt|;
name|List
modifier|*
name|versions
decl_stmt|;
name|List
modifier|*
name|dates
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|rcsnode
name|RCSNode
typedef|;
end_typedef

begin_struct
struct|struct
name|rcsversnode
block|{
name|char
modifier|*
name|version
decl_stmt|;
name|char
modifier|*
name|date
decl_stmt|;
name|char
modifier|*
name|next
decl_stmt|;
name|List
modifier|*
name|branches
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|rcsversnode
name|RCSVers
typedef|;
end_typedef

begin_comment
comment|/*  * CVS reserves all even-numbered branches for its own use.  "magic" branches  * (see rcs.c) are contained as virtual revision numbers (within symbolic  * tags only) off the RCS_MAGIC_BRANCH, which is 0.  CVS also reserves the  * ".1" branch for vendor revisions.  So, if you do your own branching, you  * should limit your use to odd branch numbers starting at 3.  */
end_comment

begin_define
define|#
directive|define
name|RCS_MAGIC_BRANCH
value|0
end_define

begin_comment
comment|/*  * exported interfaces  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
name|List
modifier|*
name|RCS_parsefiles
parameter_list|(
name|List
modifier|*
name|files
parameter_list|,
name|char
modifier|*
name|xrepos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RCSNode
modifier|*
name|RCS_parse
parameter_list|(
name|char
modifier|*
name|file
parameter_list|,
name|char
modifier|*
name|repos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RCSNode
modifier|*
name|RCS_parsercsfile
parameter_list|(
name|char
modifier|*
name|rcsfile
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|RCS_check_kflag
parameter_list|(
name|char
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|RCS_getdate
parameter_list|(
name|RCSNode
modifier|*
name|rcs
parameter_list|,
name|char
modifier|*
name|date
parameter_list|,
name|int
name|force_tag_match
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|RCS_gettag
parameter_list|(
name|RCSNode
modifier|*
name|rcs
parameter_list|,
name|char
modifier|*
name|tag
parameter_list|,
name|int
name|force_tag_match
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|RCS_getversion
parameter_list|(
name|RCSNode
modifier|*
name|rcs
parameter_list|,
name|char
modifier|*
name|tag
parameter_list|,
name|char
modifier|*
name|date
parameter_list|,
name|int
name|force_tag_match
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|RCS_magicrev
parameter_list|(
name|RCSNode
modifier|*
name|rcs
parameter_list|,
name|char
modifier|*
name|rev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|RCS_isbranch
parameter_list|(
name|char
modifier|*
name|file
parameter_list|,
name|char
modifier|*
name|rev
parameter_list|,
name|List
modifier|*
name|srcfiles
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|RCS_whatbranch
parameter_list|(
name|char
modifier|*
name|file
parameter_list|,
name|char
modifier|*
name|tag
parameter_list|,
name|List
modifier|*
name|srcfiles
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|RCS_head
parameter_list|(
name|RCSNode
modifier|*
name|rcs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|RCS_datecmp
parameter_list|(
name|char
modifier|*
name|date1
parameter_list|,
name|char
modifier|*
name|date2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|RCS_getrevtime
parameter_list|(
name|RCSNode
modifier|*
name|rcs
parameter_list|,
name|char
modifier|*
name|rev
parameter_list|,
name|char
modifier|*
name|date
parameter_list|,
name|int
name|fudge
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RCS_check_tag
parameter_list|(
name|char
modifier|*
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freercsnode
parameter_list|(
name|RCSNode
modifier|*
modifier|*
name|rnodep
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|List
modifier|*
name|RCS_parsefiles
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|RCSNode
modifier|*
name|RCS_parse
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|RCS_head
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|RCS_getversion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|RCS_magicrev
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|RCS_isbranch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|RCS_whatbranch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|RCS_gettag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|RCS_getdate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|RCS_check_kflag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RCS_check_tag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|RCS_getrevtime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|RCSNode
modifier|*
name|RCS_parsercsfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|RCS_datecmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freercsnode
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

end_unit

