begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*  *	UNIX shell  *  *	S. R. Bourne  *	Bell Telephone Laboratories  *  */
end_comment

begin_define
define|#
directive|define
name|N_RDONLY
value|0100000
end_define

begin_define
define|#
directive|define
name|N_EXPORT
value|0040000
end_define

begin_define
define|#
directive|define
name|N_ENVNAM
value|0020000
end_define

begin_define
define|#
directive|define
name|N_ENVPOS
value|0007777
end_define

begin_define
define|#
directive|define
name|N_DEFAULT
value|0
end_define

begin_struct
struct|struct
name|namnod
block|{
name|NAMPTR
name|namlft
decl_stmt|;
name|NAMPTR
name|namrgt
decl_stmt|;
name|STRING
name|namid
decl_stmt|;
name|STRING
name|namval
decl_stmt|;
name|STRING
name|namenv
decl_stmt|;
name|INT
name|namflg
decl_stmt|;
block|}
struct|;
end_struct

end_unit

