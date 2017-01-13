begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Nested struct */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|EditLine
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|History
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EditLine
modifier|*
name|el
decl_stmt|;
name|History
modifier|*
name|hist
decl_stmt|;
block|}
name|el_mode_t
typedef|;
end_typedef

begin_struct
struct|struct
name|el_modes_s
block|{
name|el_mode_t
name|command
decl_stmt|;
name|el_mode_t
name|string
decl_stmt|;
name|el_mode_t
name|filec
decl_stmt|;
name|el_mode_t
name|mime_enc
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|el_modes_s
name|elm
init|=
block|{
operator|.
name|command
operator|=
block|{
operator|.
name|el
operator|=
literal|0
block|,
operator|.
name|hist
operator|=
literal|0
block|, }
block|,
operator|.
name|string
operator|=
block|{
operator|.
name|el
operator|=
literal|0
block|,
operator|.
name|hist
operator|=
literal|0
block|, }
block|,
operator|.
name|filec
operator|=
block|{
operator|.
name|el
operator|=
literal|0
block|,
operator|.
name|hist
operator|=
literal|0
block|, }
block|, }
decl_stmt|;
end_decl_stmt

end_unit

