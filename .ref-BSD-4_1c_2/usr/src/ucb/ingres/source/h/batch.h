begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/* **  BATCH.H -- batch file declarations. ** **	Version: **		@(#)batch.h	7.1	2/5/81 */
end_comment

begin_define
define|#
directive|define
name|BATCHSIZE
value|506
end_define

begin_comment
comment|/* available buffer space */
end_comment

begin_define
define|#
directive|define
name|IDSIZE
value|6
end_define

begin_comment
comment|/* size of file id */
end_comment

begin_struct
struct|struct
name|batchbuf
block|{
name|char
name|file_id
index|[
name|IDSIZE
index|]
decl_stmt|;
comment|/* unique file name identifier */
name|char
name|bbuf
index|[
name|BATCHSIZE
index|]
decl_stmt|;
comment|/* buffer for batch storage */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|si_doms
block|{
name|short
name|rel_off
decl_stmt|;
comment|/* offset in primary tuple */
name|short
name|tupo_off
decl_stmt|;
comment|/* offset in saved tuple-old */
name|short
name|dom_size
decl_stmt|;
comment|/* width of the domain */
comment|/* if zero then domain not used */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|batchhd
block|{
name|char
name|db_name
index|[
literal|15
index|]
decl_stmt|;
comment|/* data base name */
name|char
name|rel_name
index|[
literal|13
index|]
decl_stmt|;
comment|/* relation name */
name|char
name|userid
index|[
literal|2
index|]
decl_stmt|;
comment|/* ingres user code */
name|long
name|num_updts
decl_stmt|;
comment|/* actual number of tuples to be updated */
name|short
name|mode_up
decl_stmt|;
comment|/* type of update */
name|short
name|tido_size
decl_stmt|;
comment|/* width of old_tuple_id field */
name|short
name|tupo_size
decl_stmt|;
comment|/* width of old tuple */
name|short
name|tupn_size
decl_stmt|;
comment|/* width of new tuple */
name|short
name|tidn_size
decl_stmt|;
comment|/* width of new_tuple_id field */
name|short
name|si_dcount
decl_stmt|;
comment|/* number of sec. index domains affected */
name|struct
name|si_doms
name|si
index|[
name|MAXDOM
operator|+
literal|1
index|]
decl_stmt|;
comment|/* entry for each domain with sec. index */
block|}
struct|;
end_struct

begin_decl_stmt
name|short
name|Batch_fp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor for batch file */
end_comment

begin_decl_stmt
name|short
name|Batch_cnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of bytes taken from the current buffer */
end_comment

begin_decl_stmt
name|short
name|Batch_dirty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used during update to mark a dirty page */
end_comment

begin_decl_stmt
name|short
name|Batch_lread
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of bytes last read in readbatch() */
end_comment

begin_decl_stmt
name|short
name|Batch_recovery
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE is this is recovery, else FALSE */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Fileset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* unique id of batch maker */
end_comment

begin_decl_stmt
name|struct
name|batchbuf
name|Batchbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|batchhd
name|Batchhd
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MODBATCH
value|"_SYSmod"
end_define

begin_define
define|#
directive|define
name|MODTEMP
value|"_SYSnewr"
end_define

begin_define
define|#
directive|define
name|ISAM_SORTED
value|"_SYSsort"
end_define

begin_define
define|#
directive|define
name|ISAM_DESC
value|"_SYSdesc"
end_define

begin_define
define|#
directive|define
name|ISAM_SPOOL
value|"_SYSspol"
end_define

begin_define
define|#
directive|define
name|MOD_PREBATCH
value|"_SYSpreb"
end_define

end_unit

