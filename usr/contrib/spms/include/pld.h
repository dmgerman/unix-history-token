begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Project Link Directory Definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Nomenclature  */
end_comment

begin_define
define|#
directive|define
name|PLDNAME
value|"..."
end_define

begin_comment
comment|/* project link directory */
end_comment

begin_comment
comment|/*  * Buffer sizes  */
end_comment

begin_define
define|#
directive|define
name|PD_BUFSIZE
value|1012
end_define

begin_comment
comment|/* project directory entry buf size */
end_comment

begin_comment
comment|/*  * Project link directory (PLD) flag definitions  */
end_comment

begin_define
define|#
directive|define
name|PDIRDESC
value|"dd"
end_define

begin_comment
comment|/* directory description */
end_comment

begin_define
define|#
directive|define
name|PDIRPATH
value|"dp"
end_define

begin_comment
comment|/* directory path */
end_comment

begin_define
define|#
directive|define
name|PDIRTYPE
value|"dt"
end_define

begin_comment
comment|/* directory type */
end_comment

begin_define
define|#
directive|define
name|PROOTDIR
value|"^^"
end_define

begin_comment
comment|/* project root directory flag */
end_comment

begin_comment
comment|/*  * Project link directory entry struct  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_pdir
block|{
name|unsigned
name|long
name|pd_mode
decl_stmt|;
comment|/* type of project directory */
name|unsigned
name|long
name|pd_reclen
decl_stmt|;
comment|/* actual length of this record */
name|unsigned
name|short
name|pd_alen
decl_stmt|;
comment|/* alias length */
name|unsigned
name|short
name|pd_plen
decl_stmt|;
comment|/* pathname length */
name|unsigned
name|short
name|pd_tlen
decl_stmt|;
comment|/* type labels length */
name|unsigned
name|short
name|pd_dlen
decl_stmt|;
comment|/* directory description length */
name|char
name|pd_buf
index|[
name|PD_BUFSIZE
index|]
decl_stmt|;
comment|/* project directory entry buffer */
block|}
name|PDIR
typedef|;
end_typedef

begin_comment
comment|/*  * Handy macros  */
end_comment

begin_define
define|#
directive|define
name|PD_ALIAS
parameter_list|(
name|p
parameter_list|)
value|((p).pd_buf)
end_define

begin_define
define|#
directive|define
name|PD_PATH
parameter_list|(
name|p
parameter_list|)
value|((p).pd_buf+(p).pd_alen+1)
end_define

begin_define
define|#
directive|define
name|PD_TYPE
parameter_list|(
name|p
parameter_list|)
value|((p).pd_buf+(p).pd_alen+(p).pd_plen+2)
end_define

begin_define
define|#
directive|define
name|PD_DESC
parameter_list|(
name|p
parameter_list|)
value|((p).pd_buf+(p).pd_alen+(p).pd_plen+(p).pd_tlen+3)
end_define

end_unit

