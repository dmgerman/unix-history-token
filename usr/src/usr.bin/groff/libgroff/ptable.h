begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1990 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.uucp)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file LICENSE.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<generic.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|PTABLE
parameter_list|(
name|T
parameter_list|)
value|name2(T,_ptable)
end_define

begin_define
define|#
directive|define
name|PASSOC
parameter_list|(
name|T
parameter_list|)
value|name2(T,_passoc)
end_define

begin_define
define|#
directive|define
name|PTABLE_ITERATOR
parameter_list|(
name|T
parameter_list|)
value|name2(T,_ptable_iterator)
end_define

begin_function_decl
specifier|extern
name|int
name|next_ptable_size
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|hash_string
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|declare_ptable
parameter_list|(
name|T
parameter_list|)
define|\ 									      \
value|struct PASSOC(T) {							      \   char *key;							      	      \   T *val;								      \   PASSOC(T)();								      \ };									      \ 									      \ struct PTABLE(T);							      \ 									      \ class PTABLE_ITERATOR(T) {						      \   PTABLE(T) *p;								      \   int i;								      \ public:									      \   PTABLE_ITERATOR(T)(PTABLE(T) *);					      \   int next(const char **, T **);					      \ };									      \ 									      \ class PTABLE(T) {							      \   PASSOC(T) *v;								      \   int size;								      \   int used;								      \   enum { FULL_NUM = 2, FULL_DEN = 3, INITIAL_SIZE = 17 };		      \ public:									      \   PTABLE(T)();								      \   ~PTABLE(T)();								      \   void define(const char *, T *);					      \   T *lookup(const char *);						      \   friend class PTABLE_ITERATOR(T);					      \ };
end_define

begin_define
define|#
directive|define
name|implement_ptable
parameter_list|(
name|T
parameter_list|)
define|\ 									      \
value|PASSOC(T)::PASSOC(T)()							      \ : key(0), val(0)							      \ {									      \ }									      \ 									      \ PTABLE(T)::PTABLE(T)()							      \ {									      \   v = new PASSOC(T)[size = INITIAL_SIZE];				      \   used = 0;								      \ }									      \ 									      \ PTABLE(T)::~PTABLE(T)()							      \ {									      \   for (int i = 0; i< size; i++) {					      \     delete v[i].key;							      \     delete v[i].val;							      \   }									      \ }									      \ 									      \ void PTABLE(T)::define(const char *key, T *val)				      \ {									      \   assert(key != 0);							      \   int h = hash_string(key);						      \   for (int n = h % size;						      \        v[n].key != 0;							      \        n = (n == 0 ? size - 1 : n - 1))					      \     if (strcmp(v[n].key, key) == 0) {					      \       delete v[n].val;							      \       v[n].val = val;							      \       return;								      \     }									      \   if (val == 0)								      \     return;								      \   if (used*FULL_DEN>= size*FULL_NUM) {					      \     PASSOC(T) *oldv = v;						      \     int old_size = size;						      \     size = next_ptable_size(size);					      \     v = new PASSOC(T)[size];						      \     for (int i = 0; i< old_size; i++)					      \       if (oldv[i].key != 0) {						      \ 	if (oldv[i].val == 0)						      \ 	  delete oldv[i].key;						      \ 	else {								      \ 	  for (int j = hash_string(oldv[i].key) % size;			      \ 	       v[j].key != 0;						      \ 	       j = (j == 0 ? size - 1 : j - 1))				      \ 		 ;							      \ 	  v[j].key = oldv[i].key;					      \ 	  v[j].val = oldv[i].val;					      \ 	}								      \       }									      \     for (n = h % size;							      \ 	 v[n].key != 0;							      \ 	 n = (n == 0 ? size - 1 : n - 1))				      \       ;									      \     delete oldv;							      \   }									      \   char *temp = new char[strlen(key)+1];					      \   strcpy(temp, key);							      \   v[n].key = temp;							      \   v[n].val = val;							      \   used++;								      \ }									      \ 									      \ T *PTABLE(T)::lookup(const char *key)					      \ {									      \   assert(key != 0);							      \   for (int n = hash_string(key) % size;					      \        v[n].key != 0;							      \        n = (n == 0 ? size - 1 : n - 1))					      \     if (strcmp(v[n].key, key) == 0)					      \       return v[n].val;							      \   return 0;								      \ }									      \ 									      \ PTABLE_ITERATOR(T)::PTABLE_ITERATOR(T)(PTABLE(T) *t)			      \ : p(t), i(0)								      \ {									      \ }									      \ 									      \ int PTABLE_ITERATOR(T)::next(const char **keyp, T **valp)		      \ {									      \   int size = p->size;							      \   PASSOC(T) *v = p->v;							      \   for (; i< size; i++)							      \     if (v[i].key != 0) {						      \       *keyp = v[i].key;							      \       *valp = v[i].val;							      \       i++;								      \       return 1;								      \     }									      \   return 0;								      \ }
end_define

end_unit

