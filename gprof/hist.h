begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* hist.h     Copyright 2000, 2001 Free Software Foundation, Inc.  This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_decl_stmt
specifier|extern
name|void
name|hist_read_rec
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|hist_write_hist
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|hist_assign_samples
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|hist_print
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* hist_h */
end_comment

end_unit

