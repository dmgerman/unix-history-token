begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* infblock.h -- header to use infblock.c  * Copyright (C) 1995-2002 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h   */
end_comment

begin_comment
comment|/* WARNING: this file should *not* be used by applications. It is    part of the implementation of the compression library and is    subject to change. Applications should only use zlib.h.  */
end_comment

begin_struct_decl
struct_decl|struct
name|inflate_blocks_state
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|inflate_blocks_state
name|FAR
name|inflate_blocks_statef
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|inflate_blocks_statef
modifier|*
name|inflate_blocks_new
name|OF
argument_list|(
operator|(
name|z_streamp
name|z
operator|,
name|check_func
name|c
operator|,
comment|/* check function */
name|uInt
name|w
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* window size */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inflate_blocks
name|OF
argument_list|(
operator|(
name|inflate_blocks_statef
operator|*
operator|,
name|z_streamp
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial return code */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|inflate_blocks_reset
name|OF
argument_list|(
operator|(
name|inflate_blocks_statef
operator|*
operator|,
name|z_streamp
operator|,
name|uLongf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* check value on output */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inflate_blocks_free
name|OF
argument_list|(
operator|(
name|inflate_blocks_statef
operator|*
operator|,
name|z_streamp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|inflate_set_dictionary
name|OF
argument_list|(
operator|(
name|inflate_blocks_statef
operator|*
name|s
operator|,
specifier|const
name|Bytef
operator|*
name|d
operator|,
comment|/* dictionary */
name|uInt
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dictionary length */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inflate_blocks_sync_point
name|OF
argument_list|(
operator|(
name|inflate_blocks_statef
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

