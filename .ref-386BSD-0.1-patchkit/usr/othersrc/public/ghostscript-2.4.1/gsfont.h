begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gsfont.h */
end_comment

begin_comment
comment|/* Font operations for Ghostscript library */
end_comment

begin_comment
comment|/* Requires gsmatrix.h */
end_comment

begin_comment
comment|/* A 'font directory' object (to avoid making fonts global). */
end_comment

begin_comment
comment|/* 'directory' is something of a misnomer: this structure */
end_comment

begin_comment
comment|/* actually just keeps track of the scaled font and */
end_comment

begin_comment
comment|/* rendered character caches. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|gs_font_dir_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|gs_font_dir_DEFINED
end_define

begin_typedef
typedef|typedef
name|struct
name|gs_font_dir_s
name|gs_font_dir
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Font objects */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gs_font_s
name|gs_font
typedef|;
end_typedef

begin_comment
comment|/* Initialization */
end_comment

begin_comment
comment|/* These procedures return 0 if they fail. */
end_comment

begin_decl_stmt
name|gs_font_dir
modifier|*
name|gs_font_dir_alloc
argument_list|(
name|P2
argument_list|(
name|proc_alloc_t
argument_list|,
name|proc_free_t
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gs_font_dir
modifier|*
name|gs_font_dir_alloc_limits
argument_list|(
name|P7
argument_list|(
name|proc_alloc_t
argument_list|,
name|proc_free_t
argument_list|,
name|uint
comment|/*smax*/
argument_list|,
name|uint
comment|/*bmax*/
argument_list|,
name|uint
comment|/*mmax*/
argument_list|,
name|uint
comment|/*cmax*/
argument_list|,
name|uint
comment|/*upper*/
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Font manipulations */
end_comment

begin_comment
comment|/* gs_scalefont and gs_makefont return 0 if the scaled font */
end_comment

begin_comment
comment|/* was already in the cache, 1 if a new font was created. */
end_comment

begin_comment
comment|/* The second gs_font ** argument returns a font discarded */
end_comment

begin_comment
comment|/* from the cache (or 0) in the latter case.  This is for */
end_comment

begin_comment
comment|/* the benefit of reference-counted clients. */
end_comment

begin_decl_stmt
name|int
name|gs_scalefont
argument_list|(
name|P5
argument_list|(
name|gs_font_dir
operator|*
argument_list|,
name|gs_font
operator|*
argument_list|,
name|floatp
argument_list|,
name|gs_font
operator|*
operator|*
argument_list|,
name|gs_font
operator|*
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gs_makefont
argument_list|(
name|P5
argument_list|(
name|gs_font_dir
operator|*
argument_list|,
name|gs_font
operator|*
argument_list|,
name|gs_matrix
operator|*
argument_list|,
name|gs_font
operator|*
operator|*
argument_list|,
name|gs_font
operator|*
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gs_setfont
argument_list|(
name|P2
argument_list|(
name|gs_state
operator|*
argument_list|,
name|gs_font
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gs_font
modifier|*
name|gs_currentfont
argument_list|(
name|P1
argument_list|(
name|gs_state
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gs_purge_font_from_caches
argument_list|(
name|P2
argument_list|(
name|gs_font_dir
operator|*
argument_list|,
name|gs_font
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Font cache parameter operations */
end_comment

begin_decl_stmt
name|void
name|gs_cachestatus
argument_list|(
name|P2
argument_list|(
name|gs_font_dir
operator|*
argument_list|,
name|uint
index|[
literal|7
index|]
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gs_setcachelimit
argument_list|(
name|P2
argument_list|(
name|gs_font_dir
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint
name|gs_currentcachelower
argument_list|(
name|P1
argument_list|(
name|gs_font_dir
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gs_setcachelower
argument_list|(
name|P2
argument_list|(
name|gs_font_dir
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint
name|gs_currentcacheupper
argument_list|(
name|P1
argument_list|(
name|gs_font_dir
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gs_setcacheupper
argument_list|(
name|P2
argument_list|(
name|gs_font_dir
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

