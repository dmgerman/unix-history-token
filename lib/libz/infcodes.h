begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* infcodes.h -- header to use infcodes.c  * Copyright (C) 1995-1998 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h   */
end_comment

begin_comment
comment|/* WARNING: this file should *not* be used by applications. It is    part of the implementation of the compression library and is    subject to change. Applications should only use zlib.h.  */
end_comment

begin_struct_decl
struct_decl|struct
name|inflate_codes_state
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|inflate_codes_state
name|FAR
name|inflate_codes_statef
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|inflate_codes_statef
modifier|*
name|inflate_codes_new
name|OF
argument_list|(
operator|(
name|uInt
operator|,
name|uInt
operator|,
name|inflate_huft
operator|*
operator|,
name|inflate_huft
operator|*
operator|,
name|z_streamp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inflate_codes
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

begin_decl_stmt
specifier|extern
name|void
name|inflate_codes_free
name|OF
argument_list|(
operator|(
name|inflate_codes_statef
operator|*
operator|,
name|z_streamp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

