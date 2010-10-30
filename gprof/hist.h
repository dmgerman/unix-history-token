begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* hist.h     Copyright 2000, 2001, 2002, 2004, 2005 Free Software Foundation, Inc.  This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|hist_h
end_ifndef

begin_define
define|#
directive|define
name|hist_h
end_define

begin_typedef
typedef|typedef
struct|struct
name|histogram
block|{
name|bfd_vma
name|lowpc
decl_stmt|;
name|bfd_vma
name|highpc
decl_stmt|;
name|unsigned
name|int
name|num_bins
decl_stmt|;
name|int
modifier|*
name|sample
decl_stmt|;
comment|/* Histogram samples (shorts in the file!).  */
block|}
name|histogram
typedef|;
end_typedef

begin_decl_stmt
name|histogram
modifier|*
name|histograms
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|num_histograms
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Scale factor converting samples to pc values:    each sample covers HIST_SCALE bytes.  */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|hist_scale
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|hist_read_rec
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hist_write_hist
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hist_assign_samples
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hist_print
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Checks if ADDRESS is within the range of addresses for which    we have histogram data.  Returns 1 if so and 0 otherwise.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|hist_check_address
parameter_list|(
name|unsigned
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a range of addresses for a symbol, find a histogram record     that intersects with this range, and clips the range to that    histogram record, modifying *P_LOWPC and *P_HIGHPC.        If no intersection is found, *P_LOWPC and *P_HIGHPC will be set to    one unspecified value.  If more that one intersection is found,    an error is emitted.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|hist_clip_symbol_address
parameter_list|(
name|bfd_vma
modifier|*
name|p_lowpc
parameter_list|,
name|bfd_vma
modifier|*
name|p_highpc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* hist_h */
end_comment

end_unit

