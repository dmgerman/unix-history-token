begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of objects used by the GNU Emacs undo facility.    Copyright (C) 1985 Fen Labalme and Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_enum
enum|enum
name|Ukinds
block|{
comment|/* The events that can exist in the undo 				   queue. */
name|Uboundary
block|,
comment|/* A boundary between sets of undoable things 				   */
name|Unundoable
block|,
comment|/* What's done is done -- some things can't 				   be undone */
name|Udelete
block|,
comment|/* Delete characters to perform the undo */
name|Uinsert
block|,
comment|/* Insert .... */
name|Uchange
block|,
comment|/* Replace characters */
name|Uunmod
block|,
comment|/* Clear modification-flag to perform undo */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|UndoRec
block|{
comment|/* A record of a single undo action */
name|enum
name|Ukinds
name|kind
decl_stmt|;
comment|/* the kind of action to be undone */
name|int
name|pos
decl_stmt|;
comment|/* Where dot is */
name|int
name|len
decl_stmt|;
comment|/* The extent of the undo (characters 				   inserted or deleted) */
block|}
struct|;
end_struct

begin_comment
comment|/* The undo history consists of two circular queues, one of characters and    one of UndoRecs.  When Uinsert recs are added to UndoRQ characters get    added to UndoCQ.  The position of the characters can be reconstructed by    subtracting len from the fill pointer. */
end_comment

begin_define
define|#
directive|define
name|NUndoR
value|(((1<< 13) - 4) / sizeof (struct UndoRec))
end_define

begin_define
define|#
directive|define
name|NUndoC
value|((1<< 13) - 4)
end_define

begin_comment
comment|/* Initially allocate them these sizes;  if these sizes get filled up, make them full size */
end_comment

begin_define
define|#
directive|define
name|InitNUndoR
value|8
end_define

begin_define
define|#
directive|define
name|InitNUndoC
value|(512 - 4)
end_define

begin_struct
struct|struct
name|UndoData
block|{
name|struct
name|UndoRec
modifier|*
name|undorecs
decl_stmt|;
comment|/* The undo records, NUndoR of them */
name|char
modifier|*
name|undochars
decl_stmt|;
comment|/* And the characters associated, NUndoC in all */
name|int
name|nextrec
decl_stmt|;
comment|/* Indices for storing in above two */
name|int
name|nextchar
decl_stmt|;
name|int
name|num_undorecs
decl_stmt|;
comment|/* Sizes allocated */
name|int
name|num_undochars
decl_stmt|;
block|}
struct|;
end_struct

end_unit

