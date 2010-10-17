begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* source.h     Copyright 2000, 2001, 2002 Free Software Foundation, Inc.  This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|source_h
end_ifndef

begin_define
define|#
directive|define
name|source_h
end_define

begin_typedef
typedef|typedef
struct|struct
name|source_file
block|{
name|struct
name|source_file
modifier|*
name|next
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of source file.  */
name|unsigned
name|long
name|ncalls
decl_stmt|;
comment|/* # of "calls" to this file.  */
name|int
name|num_lines
decl_stmt|;
comment|/* # of lines in file.  */
name|int
name|nalloced
decl_stmt|;
comment|/* Number of lines allocated.  */
name|void
modifier|*
modifier|*
name|line
decl_stmt|;
comment|/* Usage-dependent per-line data.  */
block|}
name|Source_File
typedef|;
end_typedef

begin_comment
comment|/* Options.  */
end_comment

begin_comment
comment|/* Create annotated output files?  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|create_annotation_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of directories to search for source files.  */
end_comment

begin_decl_stmt
specifier|extern
name|Search_List
name|src_search_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain of source-file descriptors.  */
end_comment

begin_decl_stmt
specifier|extern
name|Source_File
modifier|*
name|first_src_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Returns pointer to source file descriptor for PATH/FILENAME.  */
end_comment

begin_decl_stmt
specifier|extern
name|Source_File
modifier|*
name|source_file_lookup_path
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Source_File
modifier|*
name|source_file_lookup_name
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read source file SF output annotated source.  The annotation is at    MAX_WIDTH characters wide and for each source-line an annotation is    obtained by invoking function ANNOTE.  ARG is an argument passed to    ANNOTE that is left uninterpreted by annotate_source().     Returns a pointer to the output file (which maybe stdout) such    that summary statistics can be printed.  If the returned file    is not stdout, it should be closed when done with it.  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|annotate_source
name|PARAMS
argument_list|(
operator|(
name|Source_File
operator|*
name|sf
operator|,
name|unsigned
name|int
name|max_width
operator|,
name|void
argument_list|(
argument|*annote
argument_list|)
operator|(
name|char
operator|*
operator|,
name|unsigned
name|int
operator|,
name|int
operator|,
name|PTR
name|arg
operator|)
operator|,
name|PTR
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* source_h */
end_comment

end_unit

