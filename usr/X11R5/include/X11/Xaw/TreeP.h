begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: TreeP.h,v 1.13 90/04/13 16:39:54 jim Exp $  *  * Copyright 1990 Massachusetts Institute of Technology  * Copyright 1989 Prentice Hall  *  * Permission to use, copy, modify, and distribute this software for any  * purpose and without fee is hereby granted, provided that the above  * copyright notice appear in all copies and that both the copyright notice  * and this permission notice appear in supporting documentation.  *   * M.I.T., Prentice Hall and the authors disclaim all warranties with regard  * to this software, including all implied warranties of merchantability and  * fitness.  In no event shall M.I.T., Prentice Hall or the authors be liable  * for any special, indirect or cosequential damages or any damages whatsoever  * resulting from loss of use, data or profits, whether in an action of  * contract, negligence or other tortious action, arising out of or in  * connection with the use or performance of this software.  *   * Authors:  Jim Fulton, MIT X Consortium,  *           based on a version by Douglas Young, Prentice Hall  *   * This widget is based on the Tree widget described on pages 397-419 of  * Douglas Young's book "The X Window System, Programming and Applications   * with Xt OSF/Motif Edition."  The layout code has been rewritten to use  * additional blank space to make the structure of the graph easier to see  * as well as to support vertical trees.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawTreeP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawTreeP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Tree.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_TreeClassPart
block|{
name|int
name|ignore
decl_stmt|;
block|}
name|TreeClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TreeClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|CompositeClassPart
name|composite_class
decl_stmt|;
name|ConstraintClassPart
name|constraint_class
decl_stmt|;
name|TreeClassPart
name|tree_class
decl_stmt|;
block|}
name|TreeClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|TreeClassRec
name|treeClassRec
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* fields available through resources */
name|Dimension
name|hpad
decl_stmt|;
comment|/* hSpace/HSpace */
name|Dimension
name|vpad
decl_stmt|;
comment|/* vSpace/VSpace */
name|Dimension
name|line_width
decl_stmt|;
comment|/* lineWidth/LineWidth */
name|Pixel
name|foreground
decl_stmt|;
comment|/* foreground/Foreground */
name|XtGravity
name|gravity
decl_stmt|;
comment|/* gravity/Gravity */
name|Boolean
name|auto_reconfigure
decl_stmt|;
comment|/* autoReconfigure/AutoReconfigure */
comment|/* private fields */
name|GC
name|gc
decl_stmt|;
comment|/* used to draw lines */
name|Widget
name|tree_root
decl_stmt|;
comment|/* hidden root off all children */
name|Dimension
modifier|*
name|largest
decl_stmt|;
comment|/* list of largest per depth */
name|int
name|n_largest
decl_stmt|;
comment|/* number of elements in largest */
name|Dimension
name|maxwidth
decl_stmt|,
name|maxheight
decl_stmt|;
comment|/* for shrink wrapping */
block|}
name|TreePart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TreeRec
block|{
name|CorePart
name|core
decl_stmt|;
name|CompositePart
name|composite
decl_stmt|;
name|ConstraintPart
name|constraint
decl_stmt|;
name|TreePart
name|tree
decl_stmt|;
block|}
name|TreeRec
typedef|;
end_typedef

begin_comment
comment|/*  * structure attached to all children  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TreeConstraintsPart
block|{
comment|/* resources */
name|Widget
name|parent
decl_stmt|;
comment|/* treeParent/TreeParent */
name|GC
name|gc
decl_stmt|;
comment|/* treeGC/TreeGC */
comment|/* private data */
name|Widget
modifier|*
name|children
decl_stmt|;
name|int
name|n_children
decl_stmt|;
name|int
name|max_children
decl_stmt|;
name|Dimension
name|bbsubwidth
decl_stmt|,
name|bbsubheight
decl_stmt|;
comment|/* bounding box of sub tree */
name|Dimension
name|bbwidth
decl_stmt|,
name|bbheight
decl_stmt|;
comment|/* bounding box including node */
name|Position
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|TreeConstraintsPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TreeConstraintsRec
block|{
name|TreeConstraintsPart
name|tree
decl_stmt|;
block|}
name|TreeConstraintsRec
operator|,
typedef|*
name|TreeConstraints
typedef|;
end_typedef

begin_comment
comment|/*  * useful macros  */
end_comment

begin_define
define|#
directive|define
name|TREE_CONSTRAINT
parameter_list|(
name|w
parameter_list|)
define|\
value|((TreeConstraints)((w)->core.constraints))
end_define

begin_define
define|#
directive|define
name|TREE_INITIAL_DEPTH
value|10
end_define

begin_comment
comment|/* for allocating largest array */
end_comment

begin_define
define|#
directive|define
name|TREE_HORIZONTAL_DEFAULT_SPACING
value|20
end_define

begin_define
define|#
directive|define
name|TREE_VERTICAL_DEFAULT_SPACING
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawTreeP_h */
end_comment

end_unit

