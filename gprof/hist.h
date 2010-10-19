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

begin_decl_stmt
specifier|extern
name|bfd_vma
name|s_lowpc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lowpc from the profile file.  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_vma
name|s_highpc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Highpc from the profile file.  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_vma
name|lowpc
decl_stmt|,
name|highpc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Range profiled, in UNIT's.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|hist_num_bins
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of histogram bins.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|hist_sample
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Code histogram.  */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* hist_h */
end_comment

end_unit

