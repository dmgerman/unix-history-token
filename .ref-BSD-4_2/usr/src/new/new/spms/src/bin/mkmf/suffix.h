begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Suffix definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Suffix types   */
end_comment

begin_define
define|#
directive|define
name|SFXHEAD
value|'h'
end_define

begin_comment
comment|/* header file name suffix */
end_comment

begin_define
define|#
directive|define
name|SFXOBJ
value|'o'
end_define

begin_comment
comment|/* object file name suffix */
end_comment

begin_define
define|#
directive|define
name|SFXOUT
value|'x'
end_define

begin_comment
comment|/* executable file name suffix */
end_comment

begin_define
define|#
directive|define
name|SFXSRC
value|'s'
end_define

begin_comment
comment|/* source file name suffix */
end_comment

begin_comment
comment|/*  * Suffix table structs  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_suffix
block|{
name|char
modifier|*
name|suffix
decl_stmt|;
comment|/* points to a suffix */
name|int
name|sfxtyp
decl_stmt|;
comment|/* type of file name suffix */
name|int
name|inctyp
decl_stmt|;
comment|/* type of included file */
block|}
name|SUFFIX
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_sfxblk
block|{
name|SUFFIX
name|sfx
decl_stmt|;
comment|/* suffix struct */
name|struct
name|_sfxblk
modifier|*
name|next
decl_stmt|;
comment|/* ptr to next suffix list block */
block|}
name|SFXBLK
typedef|;
end_typedef

end_unit

