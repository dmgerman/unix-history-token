begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: Tree.h,v 1.11 91/05/04 18:59:13 rws Exp $  *  * Copyright 1990 Massachusetts Institute of Technology  * Copyright 1989 Prentice Hall  *  * Permission to use, copy, modify, and distribute this software for any  * purpose and without fee is hereby granted, provided that the above  * copyright notice appear in all copies and that both the copyright notice  * and this permission notice appear in supporting documentation.  *   * M.I.T., Prentice Hall and the authors disclaim all warranties with regard  * to this software, including all implied warranties of merchantability and  * fitness.  In no event shall M.I.T., Prentice Hall or the authors be liable  * for any special, indirect or cosequential damages or any damages whatsoever  * resulting from loss of use, data or profits, whether in an action of  * contract, negligence or other tortious action, arising out of or in  * connection with the use or performance of this software.  *   * Authors:  Jim Fulton, MIT X Consortium,  *           based on a version by Douglas Young, Prentice Hall  *   * This widget is based on the Tree widget described on pages 397-419 of  * Douglas Young's book "The X Window System, Programming and Applications   * with Xt OSF/Motif Edition."  The layout code has been rewritten to use  * additional blank space to make the structure of the graph easier to see  * as well as to support vertical trees.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawTree_h
end_ifndef

begin_define
define|#
directive|define
name|_XawTree_h
end_define

begin_include
include|#
directive|include
file|<X11/Xmu/Converters.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_comment
comment|/******************************************************************************  *   * Tree Widget (subclass of ConstraintClass)  *   ******************************************************************************  *   * Parameters:  *   *  Name                Class              Type            Default  *  ----                -----              ----            -------  *   *  autoReconfigure     AutoReconfigure    Boolean         FALSE  *  background          Background         Pixel           XtDefaultBackground  *  foreground          Foreground         Pixel           XtDefaultForeground  *  gravity             Gravity            XtGravity       West  *  hSpace              HSpace             Dimension       20  *  lineWidth           LineWidth          Dimension       0  *  vSpace              VSpace             Dimension       6  *   *   * Constraint Resources attached to children:  *   *  treeGC              TreeGC             GC              NULL  *  treeParent          TreeParent         Widget          NULL  *   *   *****************************************************************************/
end_comment

begin_comment
comment|/* new instance field names */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtStringDefs_h_
end_ifndef

begin_define
define|#
directive|define
name|XtNhSpace
value|"hSpace"
end_define

begin_define
define|#
directive|define
name|XtNvSpace
value|"vSpace"
end_define

begin_define
define|#
directive|define
name|XtCHSpace
value|"HSpace"
end_define

begin_define
define|#
directive|define
name|XtCVSpace
value|"VSpace"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XtNautoReconfigure
value|"autoReconfigure"
end_define

begin_define
define|#
directive|define
name|XtNlineWidth
value|"lineWidth"
end_define

begin_define
define|#
directive|define
name|XtNtreeGC
value|"treeGC"
end_define

begin_define
define|#
directive|define
name|XtNtreeParent
value|"treeParent"
end_define

begin_define
define|#
directive|define
name|XtNgravity
value|"gravity"
end_define

begin_comment
comment|/* new class field names */
end_comment

begin_define
define|#
directive|define
name|XtCAutoReconfigure
value|"AutoReconfigure"
end_define

begin_define
define|#
directive|define
name|XtCLineWidth
value|"LineWidth"
end_define

begin_define
define|#
directive|define
name|XtCTreeGC
value|"TreeGC"
end_define

begin_define
define|#
directive|define
name|XtCTreeParent
value|"TreeParent"
end_define

begin_define
define|#
directive|define
name|XtCGravity
value|"Gravity"
end_define

begin_define
define|#
directive|define
name|XtRGC
value|"GC"
end_define

begin_comment
comment|/* external declarations */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|treeWidgetClass
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_TreeClassRec
modifier|*
name|TreeWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_TreeRec
modifier|*
name|TreeWidget
typedef|;
end_typedef

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|void
name|XawTreeForceLayout
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* tree */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawTree_h */
end_comment

end_unit

