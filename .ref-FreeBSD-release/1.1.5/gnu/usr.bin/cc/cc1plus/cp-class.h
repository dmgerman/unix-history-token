begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Variables and structures for overloading rules.    Copyright (C) 1993 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* The following structure is used when comparing various alternatives    for overloading.  The unsigned quantity `strikes.i' is used    for fast comparison of two possibilities.  This number is an    aggregate of four constituents:       EVIL: if this is non-zero, then the candidate should not be considered      ELLIPSIS: if this is non-zero, then some actual argument has been matched                against an ellipsis      USER: if this is non-zero, then a user-defined type conversion is needed      B_OR_D: if this is non-zero, then use a base pointer instead of the              type of the pointer we started with.      EASY: if this is non-zero, then we have a builtin conversion            (such as int to long, int to float, etc) to do.     If two candidates require user-defined type conversions, and the    type conversions are not identical, then an ambiguity error    is reported.     If two candidates agree on user-defined type conversions,    and one uses pointers of strictly higher type (derived where    another uses base), then that alternative is silently chosen.     If two candidates have a non-monotonic derived/base pointer    relationship, and/or a non-monotonic easy conversion relationship,    then a warning is emitted to show which paths are possible, and    which one is being chosen.     For example:     int i;    double x;     overload f;    int f (int, int);    double f (double, double);     f (i, x);	// draws a warning     struct B    {      f (int);    } *bb;    struct D : B    {      f (double);    } *dd;     dd->f (x);	// exact match    dd->f (i);	// draws warning     Note that this technique really only works for 255 arguments.  Perhaps    this is not enough.  */
end_comment

begin_struct
struct|struct
name|candidate
block|{
name|tree
name|function
decl_stmt|;
comment|/* A FUNCTION_DECL */
name|unsigned
name|char
name|evil
decl_stmt|;
comment|/* !0 if this will never convert.  */
name|unsigned
name|char
name|ellipsis
decl_stmt|;
comment|/* !0 if a match against an ellipsis occurred */
name|unsigned
name|char
name|user
decl_stmt|;
comment|/* !0 if at least one user-defined type conv.  */
name|unsigned
name|short
name|b_or_d
decl_stmt|;
comment|/* count number of derived->base or 				   base->derived conv.  */
name|unsigned
name|short
name|easy
decl_stmt|;
comment|/* count number of builtin type conv.  */
name|tree
name|arg
decl_stmt|;
comment|/* first parm to function.  */
name|unsigned
name|short
modifier|*
name|harshness
decl_stmt|;
comment|/* Indexed by argument number, encodes 				   evil, user, d_to_b, and easy strikes for 				   that argument. 				   At end of array, we store the index+1 				   of where we started using default 				   parameters, or 0 if there are none.  */
union|union
block|{
name|tree
name|field
decl_stmt|;
comment|/* If no evil strikes, the FUNCTION_DECL of 				   the function (if a member function).  */
name|int
name|bad_arg
decl_stmt|;
comment|/* the index of the first bad argument: 				   0 if no bad arguments> 0 is first bad argument 				   -1 if extra actual arguments 				   -2 if too few actual arguments. 				   -3 if const/non const method mismatch. 				   -4 if type unification failed. 				   -5 if contravariance violation.  */
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|rank_for_overload
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Variables shared between cp-class.c and cp-call.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|n_vtables
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|n_vtable_entries
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|n_vtable_searches
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|n_vtable_elems
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|n_convert_harshness
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|n_compute_conversion_costs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|n_build_method_call
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|n_inner_fields_searched
decl_stmt|;
end_decl_stmt

end_unit

