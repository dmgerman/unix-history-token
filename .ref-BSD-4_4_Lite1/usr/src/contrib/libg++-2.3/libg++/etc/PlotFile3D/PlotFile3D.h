begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header file for PlotFile3D class -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1990 Free Software Foundation     written by J. Thomas Ngo, Harvard University  This file is part of the GNU C++ Library.  The GNU C++ Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU General Public License for full details.  Everyone is granted permission to copy, modify and redistribute The GNU C++ Library, but only under the conditions described in the GNU General Public License.  A copy of this license is supposed to have been given to you along with The GNU C++ Library so you can know your rights and responsibilities.  It should be in a file named COPYING. Among other things, the copyright notice and this notice must be preserved on all copies.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PlotFile3D_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_PlotFile3D_h
value|1
end_define

begin_comment
comment|//===========================================================================
end_comment

begin_comment
comment|// Top-level declarations
end_comment

begin_comment
comment|//===========================================================================
end_comment

begin_include
include|#
directive|include
file|<builtin.h>
end_include

begin_include
include|#
directive|include
file|<bool.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<PlotFile.h>
end_include

begin_include
include|#
directive|include
file|"Vec3D.h"
end_include

begin_decl_stmt
name|class
name|PlotFile3D
range|:
name|private
name|PlotFile
block|{
name|protected
operator|:
comment|// constant implementation parameters
specifier|const
name|int
name|umini
operator|=
literal|0
block|;
comment|// Plot limits to send to 2D package
specifier|const
name|int
name|vmini
operator|=
literal|0
block|;
specifier|const
name|int
name|umaxi
operator|=
literal|3120
block|;
specifier|const
name|int
name|vmaxi
operator|=
literal|3120
block|;
specifier|const
name|double
name|margin
operator|=
literal|0.9
block|;
comment|// How much leeway to give on edge of pic
comment|// internal state
name|Vec3D
name|intp
block|;
comment|// Internal idea of where cursor is in 3D
name|bool
name|valid3D
block|;
comment|// true if 3D cursor valid
name|bool
name|stereo
block|;
comment|// true for stereo images
name|int
name|stereo_offset
block|;
comment|// Stereo separation in pixels (computed)
name|Vec3D
name|ul
block|,
name|vl
block|,
name|wl
block|;
comment|// Basis vectors for the left or main image
name|Vec3D
name|ur
block|,
name|vr
block|,
name|wr
block|;
comment|// Basis for alternate image, if stereo
name|double
name|scale
block|;
comment|// Amount by which to stretch u,v to fit
name|double
name|uorig
block|,
name|vorig
block|;
comment|// Offset for scaled u, v
name|double
operator|*
name|sintab
block|;
comment|// tables, needed by circle, sphere
name|double
operator|*
name|costab
block|;
name|int
name|ppq
block|;
comment|// points per quadrant in current table
comment|// helper functions
comment|// project 3D into 2D
name|void
name|project
argument_list|(
argument|int&
argument_list|,
argument|int&
argument_list|,
argument|const Vec3D&
argument_list|,
argument|const Vec3D&
argument_list|,
argument|const Vec3D& rel
argument_list|)
specifier|const
block|;
comment|// All clipping handled here
name|void
name|line2D
argument_list|(
argument|const int u0
argument_list|,
argument|const int v0
argument_list|,
argument|const int u1
argument_list|,
argument|const int v1
argument_list|)
block|;
comment|// Methods to handle state of 3D cursor:  defined or undefined
name|void
name|define3D
argument_list|()
block|;
name|void
name|undefine3D
argument_list|()
block|;
name|void
name|must_be_valid3D
argument_list|()
block|;
name|void
name|initialize
argument_list|(
argument|bool stereo
argument_list|,
argument|double th
argument_list|,
argument|double ph
argument_list|)
block|;
name|public
operator|:
name|PlotFile3D
argument_list|(
argument|bool st=FALSE
argument_list|,
argument|double th=M_PI/
literal|12
argument_list|,
argument|double ph=M_PI/
literal|3
argument_list|)
operator|:
name|PlotFile
argument_list|()
block|{
name|initialize
argument_list|(
name|st
argument_list|,
name|th
argument_list|,
name|ph
argument_list|)
block|; }
name|PlotFile3D
argument_list|(
argument|int fd
argument_list|,
argument|bool st=FALSE
argument_list|,
argument|double th=M_PI/
literal|12
argument_list|,
argument|double ph=M_PI/
literal|3
argument_list|)
operator|:
name|PlotFile
argument_list|(
argument|fd
argument_list|)
block|{
name|initialize
argument_list|(
name|st
argument_list|,
name|th
argument_list|,
name|ph
argument_list|)
block|; }
name|PlotFile3D
argument_list|(
argument|const char *name
argument_list|,
argument|bool st=FALSE
argument_list|,
argument|double th=M_PI/
literal|12
argument_list|,
argument|double ph=M_PI/
literal|3
argument_list|)
operator|:
name|PlotFile
argument_list|(
argument|name
argument_list|)
block|{
name|initialize
argument_list|(
name|st
argument_list|,
name|th
argument_list|,
name|ph
argument_list|)
block|; }
ifdef|#
directive|ifdef
name|_OLD_STREAMS
name|PlotFile3D
argument_list|(
argument|FILE* fp
argument_list|,
argument|bool st=FALSE
argument_list|,
argument|double th=M_PI/
literal|12
argument_list|,
argument|double ph=M_PI/
literal|3
argument_list|)
operator|:
name|PlotFile
argument_list|(
argument|fp
argument_list|)
block|{
name|initialize
argument_list|(
name|st
argument_list|,
name|th
argument_list|,
name|ph
argument_list|)
block|; }
endif|#
directive|endif
operator|~
name|PlotFile3D
argument_list|()
block|;
comment|// plot commands taking Vec3D args
name|PlotFile3D
operator|&
name|space
argument_list|(
specifier|const
name|Vec3D
operator|&
name|p0
argument_list|,
specifier|const
name|Vec3D
operator|&
name|p1
argument_list|)
block|;
name|PlotFile3D
operator|&
name|move
argument_list|(
specifier|const
name|Vec3D
operator|&
name|p
argument_list|)
block|;
name|PlotFile3D
operator|&
name|cont
argument_list|(
specifier|const
name|Vec3D
operator|&
name|p
argument_list|)
block|;
name|PlotFile3D
operator|&
name|line
argument_list|(
specifier|const
name|Vec3D
operator|&
name|p0
argument_list|,
specifier|const
name|Vec3D
operator|&
name|p1
argument_list|)
block|;
name|PlotFile3D
operator|&
name|point
argument_list|(
specifier|const
name|Vec3D
operator|&
name|p
argument_list|)
block|;
name|PlotFile3D
operator|&
name|box
argument_list|(
specifier|const
name|Vec3D
operator|&
name|p0
argument_list|,
specifier|const
name|Vec3D
operator|&
name|p1
argument_list|)
block|;
name|PlotFile3D
operator|&
name|circle
argument_list|(
argument|const Vec3D& center
argument_list|,
argument|const Vec3D& radius
argument_list|,
argument|const int points_per_quadrant =
literal|10
argument_list|)
block|;
comment|// This one has no PlotFile analog
name|PlotFile3D
operator|&
name|sphere
argument_list|(
argument|const Vec3D& center
argument_list|,
argument|const Vec3D& radius
argument_list|,
argument|const int points_per_quadrant =
literal|10
argument_list|)
block|;
comment|// versions taking raw coordinates
name|PlotFile3D
operator|&
name|space
argument_list|(
argument|const double x0
argument_list|,
argument|const double y0
argument_list|,
argument|const double z0
argument_list|,
argument|const double x1
argument_list|,
argument|const double y1
argument_list|,
argument|const double z1
argument_list|)
block|;
name|PlotFile3D
operator|&
name|move
argument_list|(
argument|const double xi
argument_list|,
argument|const double yi
argument_list|,
argument|const double zi
argument_list|)
block|;
name|PlotFile3D
operator|&
name|cont
argument_list|(
argument|const double xi
argument_list|,
argument|const double yi
argument_list|,
argument|const double zi
argument_list|)
block|;
name|PlotFile3D
operator|&
name|line
argument_list|(
argument|const double x0
argument_list|,
argument|const double y0
argument_list|,
argument|const double z0
argument_list|,
argument|const double x1
argument_list|,
argument|const double y1
argument_list|,
argument|const double z1
argument_list|)
block|;
name|PlotFile3D
operator|&
name|point
argument_list|(
argument|const double xi
argument_list|,
argument|const double yi
argument_list|,
argument|const double zi
argument_list|)
block|;
name|PlotFile3D
operator|&
name|box
argument_list|(
argument|const double x0
argument_list|,
argument|const double y0
argument_list|,
argument|const double z0
argument_list|,
argument|const double x1
argument_list|,
argument|const double y1
argument_list|,
argument|const double z1
argument_list|)
block|;
name|PlotFile3D
operator|&
name|circle
argument_list|(
argument|const double cx
argument_list|,
argument|const double cy
argument_list|,
argument|const double cz
argument_list|,
argument|const double rx
argument_list|,
argument|const double ry
argument_list|,
argument|const double rz
argument_list|,
argument|const int points_per_quadrant =
literal|10
argument_list|)
block|;
name|PlotFile3D
operator|&
name|sphere
argument_list|(
argument|const double cx
argument_list|,
argument|const double cy
argument_list|,
argument|const double cz
argument_list|,
argument|const double rx
argument_list|,
argument|const double ry
argument_list|,
argument|const double rz
argument_list|,
argument|const int points_per_quadrant =
literal|10
argument_list|)
block|;
comment|// For convenience
name|PlotFile3D
operator|&
name|home
argument_list|()
block|;
comment|// Move cursor to upper left, out of the way
comment|// These plot commands get passed right to PlotFile
name|PlotFile3D
operator|&
name|erase
argument_list|()
block|;
name|PlotFile3D
operator|&
name|label
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|)
block|;
name|PlotFile3D
operator|&
name|linemod
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|)
block|;
comment|// Error handling
name|void
name|error
argument_list|(
argument|const char* s
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Handling of valid3D
end_comment

begin_expr_stmt
specifier|inline
name|void
name|PlotFile3D
operator|::
name|define3D
argument_list|()
block|{
name|valid3D
operator|=
name|TRUE
block|; }
specifier|inline
name|void
name|PlotFile3D
operator|::
name|undefine3D
argument_list|()
block|{
name|valid3D
operator|=
name|FALSE
block|; }
specifier|inline
name|void
name|PlotFile3D
operator|::
name|must_be_valid3D
argument_list|()
block|{
name|assert
argument_list|(
name|valid3D
argument_list|)
block|; }
comment|// Versions of routines that take coordinates as Vec3D
specifier|inline
name|PlotFile3D
operator|&
name|PlotFile3D
operator|::
name|line
argument_list|(
argument|const Vec3D& p0
argument_list|,
argument|const Vec3D& p1
argument_list|)
block|{
name|move
argument_list|(
name|p0
argument_list|)
block|;
return|return
name|cont
argument_list|(
name|p1
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|PlotFile3D
operator|&
name|PlotFile3D
operator|::
name|point
argument_list|(
argument|const Vec3D& p
argument_list|)
block|{
return|return
name|line
argument_list|(
name|p
argument_list|,
name|p
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Versions of routines that take coordinates as doubles
end_comment

begin_expr_stmt
specifier|inline
name|PlotFile3D
operator|&
name|PlotFile3D
operator|::
name|line
argument_list|(
argument|const double x0
argument_list|,
argument|const double y0
argument_list|,
argument|const double z0
argument_list|,
argument|const double x1
argument_list|,
argument|const double y1
argument_list|,
argument|const double z1
argument_list|)
block|{
name|Vec3D
name|p0
argument_list|(
name|x0
argument_list|,
name|y0
argument_list|,
name|z0
argument_list|)
block|;
name|Vec3D
name|p1
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|,
name|z1
argument_list|)
block|;
name|move
argument_list|(
name|p0
argument_list|)
block|;
return|return
name|cont
argument_list|(
name|p1
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|PlotFile3D
operator|&
name|PlotFile3D
operator|::
name|point
argument_list|(
argument|const double xi
argument_list|,
argument|const double yi
argument_list|,
argument|const double zi
argument_list|)
block|{
name|Vec3D
name|p
argument_list|(
name|xi
argument_list|,
name|yi
argument_list|,
name|zi
argument_list|)
block|;
return|return
name|line
argument_list|(
name|p
argument_list|,
name|p
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Versions of routines that take no coordinates
end_comment

begin_expr_stmt
specifier|inline
name|PlotFile3D
operator|&
name|PlotFile3D
operator|::
name|erase
argument_list|()
block|{
name|PlotFile
operator|::
name|erase
argument_list|()
block|;
return|return
name|home
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|PlotFile3D
operator|&
name|PlotFile3D
operator|::
name|label
argument_list|(
argument|const char* s
argument_list|)
block|{
name|PlotFile
operator|::
name|label
argument_list|(
name|s
argument_list|)
block|;
return|return
name|home
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|PlotFile3D
operator|&
name|PlotFile3D
operator|::
name|linemod
argument_list|(
argument|const char* s
argument_list|)
block|{
name|PlotFile
operator|::
name|linemod
argument_list|(
name|s
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _PlotFile3D_h
end_comment

end_unit

