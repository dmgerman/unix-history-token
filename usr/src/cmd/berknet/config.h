begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	These are machine-configuration dependent 	tables.  To add a machine, be sure to update all 	these tables, add the "ifdef" entry in "mach.h", 	and add config? to gothru() in sub.c. 	For Berkeley, this file corresponds to the following network:  			C70 			 | 			 | 			 | 			 | 	IngVAX          ARPA----Onyx 	  |		 | 	  |		 | 	  |		 | 	  |		 | 	Ing70-----------CSVAX---Kim	A              B 	   		 |		|              | 		         |		|              | 	            	 |		|              | 	   		 |		|              | 	MathStat--------Cory------------C--------------D 			 |		|	       | 			 |		|	       | 			 |		|	       | 			 |		|	       | 	EECS40----------ESVAX		E-------F     SRC 	   		 |	       /|\ 	   		 |     	      / | \ 	   		 |	     /	|  \ 	   		 |	    /	|   \ 	VLSI------------Image	 Virus	Q    G 			 | 			 | 			 | 			CAD  	The tables must be consistent.   	For RAND, these tables are:  		VAX (C) ---------GRAPHICS (A)------- TP (B)  	For NOSC, these tables are:  		   FCCMM ------ ATTS ------ MSSF ------ CCMM 				/ \ 			       /   \ 			      /     \ 			     /       \ 		OT34 ---- GATE40    ING70 			    | 			    | 			   PWB    */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RAND
end_ifdef

begin_comment
comment|/* GRAPHICS = A */
end_comment

begin_decl_stmt
name|char
name|configA
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'a'
block|,
literal|'b'
block|,
literal|'c'
block|,
literal|000
block|,
literal|000
block|,
comment|/* a,b,c,d,e */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TP = B */
end_comment

begin_decl_stmt
name|char
name|configB
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'a'
block|,
literal|'b'
block|,
literal|'a'
block|,
literal|000
block|,
literal|000
block|,
comment|/* a,b,c,d,e */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* VAX = C */
end_comment

begin_decl_stmt
name|char
name|configC
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'a'
block|,
literal|'a'
block|,
literal|'c'
block|,
literal|000
block|,
literal|000
block|,
comment|/* a,b,c,d,e */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if machtype is 	M_CC		netlpr will do lpr w/o an acct. 			Will pre-encrypt the password. 	M_INGRES	will allow higher file lengths. 	M_OTHER		will give no unusual effects. (when in doubt, machtype should be M_OTHER) */
end_comment

begin_decl_stmt
name|char
name|machtype
index|[]
init|=
block|{
name|M_OTHER
block|,
name|M_OTHER
block|,
name|M_OTHER
block|,
literal|0
block|,
literal|0
block|,
comment|/* a,b,c,d,e */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* f,g,h,i,j */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* k,l,m,n,o */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* p,q,r,s,t */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* u,v,w,x,y */
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* z */
end_comment

begin_comment
comment|/* this is basically the default machine for each local machine */
end_comment

begin_decl_stmt
name|char
name|remtable
index|[]
init|=
block|{
literal|'b'
block|,
literal|'a'
block|,
literal|'a'
block|,
literal|000
block|,
literal|000
block|,
comment|/* a,b,c,d,e */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bad login names */
end_comment

begin_decl_stmt
name|struct
name|bstruct
name|btable
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this table shows the correspondence between    machine names like 'Cory' and their internal    names, like 'y' */
end_comment

begin_struct
specifier|static
struct|struct
name|tt
block|{
name|char
modifier|*
name|bigname
decl_stmt|;
name|char
name|lname
decl_stmt|;
block|}
name|table
index|[]
init|=
block|{
literal|"Graphics"
block|,
literal|'a'
block|,
literal|"TP"
block|,
literal|'b'
block|,
literal|"VAX"
block|,
literal|'c'
block|,
literal|0
block|,
literal|0
block|}
struct|;
end_struct

begin_comment
comment|/* end of Rand definitions */
end_comment

begin_endif
endif|#
directive|endif
endif|RAND
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NOSC
end_ifdef

begin_comment
comment|/* Naval Ocean Systems Center */
end_comment

begin_comment
comment|/* atts (a) */
end_comment

begin_decl_stmt
name|char
name|configA
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'a'
block|,
literal|000
block|,
literal|'m'
block|,
literal|000
block|,
literal|000
block|,
comment|/* a,b,c,d,e */
literal|'f'
block|,
literal|'g'
block|,
literal|000
block|,
literal|'i'
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'m'
block|,
literal|000
block|,
literal|'g'
block|,
comment|/* k,l,m,n,o */
literal|'g'
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ccmm (c) */
end_comment

begin_decl_stmt
name|char
name|configC
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'m'
block|,
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
literal|000
block|,
comment|/* a,b,c,d,e */
literal|'m'
block|,
literal|'m'
block|,
literal|000
block|,
literal|'m'
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'m'
block|,
literal|000
block|,
literal|'m'
block|,
comment|/* k,l,m,n,o */
literal|'m'
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ccmm (f) */
end_comment

begin_decl_stmt
name|char
name|configF
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'a'
block|,
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
literal|000
block|,
comment|/* a,b,c,d,e */
literal|'f'
block|,
literal|'a'
block|,
literal|000
block|,
literal|'a'
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'a'
block|,
literal|000
block|,
literal|'a'
block|,
comment|/* k,l,a,n,o */
literal|'a'
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mssf (m) */
end_comment

begin_decl_stmt
name|char
name|configM
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'a'
block|,
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
literal|000
block|,
comment|/* a,b,c,d,e */
literal|'a'
block|,
literal|'a'
block|,
literal|000
block|,
literal|'a'
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'m'
block|,
literal|000
block|,
literal|'a'
block|,
comment|/* k,l,m,n,o */
literal|'a'
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ingres (i) proposed */
end_comment

begin_decl_stmt
name|char
name|configI
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'a'
block|,
literal|000
block|,
literal|'a'
block|,
literal|000
block|,
literal|000
block|,
comment|/* a,b,c,d,e */
literal|'a'
block|,
literal|'a'
block|,
literal|000
block|,
literal|'i'
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'a'
block|,
literal|000
block|,
literal|'a'
block|,
comment|/* k,l,m,n,o */
literal|'a'
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nosc-cc gateway 40 (g) */
end_comment

begin_decl_stmt
name|char
name|configG
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'a'
block|,
literal|000
block|,
literal|'a'
block|,
literal|000
block|,
literal|000
block|,
comment|/* a,b,c,d,e */
literal|'a'
block|,
literal|'g'
block|,
literal|000
block|,
literal|'a'
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'a'
block|,
literal|000
block|,
literal|'g'
block|,
comment|/* k,l,m,n,o */
literal|'p'
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ocean tech 34 (o) */
end_comment

begin_decl_stmt
name|char
name|configO
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'g'
block|,
literal|000
block|,
literal|'g'
block|,
literal|000
block|,
literal|000
block|,
comment|/* a,b,c,d,e */
literal|'g'
block|,
literal|'g'
block|,
literal|000
block|,
literal|'g'
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'g'
block|,
literal|000
block|,
literal|'o'
block|,
comment|/* k,l,m,n,o */
literal|'g'
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pwb at nosc (p) */
end_comment

begin_decl_stmt
name|char
name|configP
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'g'
block|,
literal|000
block|,
literal|'g'
block|,
literal|000
block|,
literal|000
block|,
comment|/* a,b,c,d,e */
literal|'g'
block|,
literal|'g'
block|,
literal|000
block|,
literal|'g'
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'g'
block|,
literal|000
block|,
literal|'g'
block|,
comment|/* k,l,m,n,o */
literal|'p'
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this table is used by netlpr to do lpr w/o an acct    and by net and netdaemon to do pre-emption */
end_comment

begin_comment
comment|/* sub.c uses the table in initdaemon to check machine    type - errormsg may be ignored */
end_comment

begin_decl_stmt
name|char
name|machtype
index|[]
init|=
block|{
name|M_CC
block|,
literal|0
block|,
name|M_OTHER
block|,
literal|0
block|,
literal|0
block|,
comment|/* a,b,c,d,e */
name|M_OTHER
block|,
name|M_OTHER
block|,
literal|0
block|,
name|M_INGRES
block|,
literal|0
block|,
comment|/* f,g,h,i,j */
literal|0
block|,
literal|0
block|,
name|M_CC
block|,
literal|0
block|,
name|M_OTHER
block|,
comment|/* k,l,m,n,o */
name|M_OTHER
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* p,q,r,s,t */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* u,v,w,x,y */
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* z */
end_comment

begin_comment
comment|/* this is basically the default machine for each local machine */
end_comment

begin_decl_stmt
name|char
name|remtable
index|[]
init|=
block|{
literal|'m'
block|,
literal|000
block|,
literal|'m'
block|,
literal|000
block|,
literal|000
block|,
comment|/* a,b,c,d,e */
literal|'a'
block|,
literal|'a'
block|,
literal|000
block|,
literal|'a'
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'a'
block|,
literal|000
block|,
literal|'g'
block|,
comment|/* k,l,m,n,o */
literal|'g'
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bad login names */
end_comment

begin_decl_stmt
name|struct
name|bstruct
name|btable
index|[]
init|=
block|{
literal|"op"
block|,
literal|'a'
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this table shows the correspondence between    machine names like 'Cory' and their internal    names, like 'y' */
end_comment

begin_struct
specifier|static
struct|struct
name|tt
block|{
name|char
modifier|*
name|bigname
decl_stmt|;
name|char
name|lname
decl_stmt|;
block|}
name|table
index|[]
init|=
block|{
literal|"ATTS"
block|,
literal|'a'
block|,
literal|"CCMM"
block|,
literal|'c'
block|,
literal|"FCCMM"
block|,
literal|'f'
block|,
literal|"MSSF"
block|,
literal|'m'
block|,
literal|"INGRES"
block|,
literal|'i'
block|,
literal|"GATEWAY"
block|,
literal|'g'
block|,
literal|"OT34"
block|,
literal|'o'
block|,
literal|"PWB"
block|,
literal|'p'
block|,
literal|0
block|,
literal|0
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
endif|NOSC
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BERKELEY
end_ifdef

begin_comment
comment|/* Berkeley definitions */
end_comment

begin_comment
comment|/* Computer Center A Machine (A) */
end_comment

begin_decl_stmt
name|char
name|configA
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'a'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* a,b,c,d,e */
literal|'c'
block|,
literal|'c'
block|,
literal|000
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* f,g,h,i,j */
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* k,l,m,n,o */
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* p,q,r,s,t */
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* u,v,w,x,y */
literal|'c'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Computer Center B Machine (B) */
end_comment

begin_decl_stmt
name|char
name|configB
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'e'
block|,
literal|'b'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
comment|/* a,b,c,d,e */
literal|'e'
block|,
literal|'e'
block|,
literal|000
block|,
literal|'e'
block|,
literal|'e'
block|,
comment|/* f,g,h,i,j */
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
comment|/* k,l,m,n,o */
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
comment|/* p,q,r,s,t */
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
comment|/* u,v,w,x,y */
literal|'e'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Computer Center C Machine (C) */
end_comment

begin_decl_stmt
name|char
name|configC
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'a'
block|,
literal|'e'
block|,
literal|'c'
block|,
literal|'g'
block|,
literal|'e'
block|,
comment|/* a,b,c,d,e */
literal|'g'
block|,
literal|'g'
block|,
literal|000
block|,
literal|'g'
block|,
literal|'g'
block|,
comment|/* f,g,h,i,j */
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
comment|/* k,l,m,n,o */
literal|'g'
block|,
literal|'e'
block|,
literal|'g'
block|,
literal|'e'
block|,
literal|'y'
block|,
comment|/* p,q,r,s,t */
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'y'
block|,
comment|/* u,v,w,x,y */
literal|'g'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Computer Center D Machine (D) */
end_comment

begin_decl_stmt
name|char
name|configD
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'d'
block|,
literal|'g'
block|,
comment|/* a,b,c,d,e */
literal|'g'
block|,
literal|'g'
block|,
literal|000
block|,
literal|'g'
block|,
literal|'g'
block|,
comment|/* f,g,h,i,j */
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
comment|/* k,l,m,n,o */
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
comment|/* p,q,r,s,t */
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
comment|/* u,v,w,x,y */
literal|'g'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Computer Center E Machine (E) */
end_comment

begin_decl_stmt
name|char
name|configE
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'c'
block|,
literal|'b'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'e'
block|,
comment|/* a,b,c,d,e */
literal|'g'
block|,
literal|'g'
block|,
literal|000
block|,
literal|'g'
block|,
literal|'g'
block|,
comment|/* f,g,h,i,j */
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
comment|/* k,l,m,n,o */
literal|'g'
block|,
literal|'e'
block|,
literal|'g'
block|,
literal|'s'
block|,
literal|'y'
block|,
comment|/* p,q,r,s,t */
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'c'
block|,
comment|/* u,v,w,x,y */
literal|'g'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Computer Center F Machine (F) */
end_comment

begin_decl_stmt
name|char
name|configF
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
comment|/* a,b,c,d,e */
literal|'f'
block|,
literal|'g'
block|,
literal|000
block|,
literal|'g'
block|,
literal|'g'
block|,
comment|/* f,g,h,i,j */
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
comment|/* k,l,m,n,o */
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
comment|/* p,q,r,s,t */
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
comment|/* u,v,w,x,y */
literal|'g'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Computer Center G Machine (Comp Center VAX) */
end_comment

begin_decl_stmt
name|char
name|configG
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'d'
block|,
literal|'c'
block|,
comment|/* a,b,c,d,e */
literal|'f'
block|,
literal|'g'
block|,
literal|000
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* f,g,h,i,j */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* k,l,m,n,o */
literal|'k'
block|,
literal|'c'
block|,
literal|'k'
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* p,q,r,s,t */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'c'
block|,
comment|/* u,v,w,x,y */
literal|'k'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Project INGRES 11/70 (Ing70) */
end_comment

begin_decl_stmt
name|char
name|configI
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'j'
block|,
literal|'j'
block|,
literal|'j'
block|,
literal|'j'
block|,
literal|'j'
block|,
comment|/* a,b,c,d,e */
literal|'j'
block|,
literal|'j'
block|,
literal|000
block|,
literal|'i'
block|,
literal|'j'
block|,
comment|/* f,g,h,i,j */
literal|'j'
block|,
literal|'j'
block|,
literal|'j'
block|,
literal|'j'
block|,
literal|'j'
block|,
comment|/* k,l,m,n,o */
literal|'j'
block|,
literal|'j'
block|,
literal|'j'
block|,
literal|'j'
block|,
literal|'j'
block|,
comment|/* p,q,r,s,t */
literal|'j'
block|,
literal|'j'
block|,
literal|'j'
block|,
literal|'j'
block|,
literal|'j'
block|,
comment|/* u,v,w,x,y */
literal|'j'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Project INGRES VAX (IngVAX) */
end_comment

begin_decl_stmt
name|char
name|configJ
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* a,b,c,d,e */
literal|'k'
block|,
literal|'k'
block|,
literal|000
block|,
literal|'i'
block|,
literal|'k'
block|,
comment|/* f,g,h,i,j */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* k,l,m,n,o */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* p,q,r,s,t */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* u,v,w,x,y */
literal|'k'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* UUCP gateway VAX (UCBVAX) */
end_comment

begin_decl_stmt
name|char
name|configK
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'g'
block|,
comment|/* a,b,c,d,e */
literal|'g'
block|,
literal|'g'
block|,
literal|000
block|,
literal|'j'
block|,
literal|'j'
block|,
comment|/* f,g,h,i,j */
literal|'k'
block|,
literal|'p'
block|,
literal|'p'
block|,
literal|'n'
block|,
literal|'p'
block|,
comment|/* k,l,m,n,o */
literal|'p'
block|,
literal|'g'
block|,
literal|'r'
block|,
literal|'g'
block|,
literal|'p'
block|,
comment|/* p,q,r,s,t */
literal|'u'
block|,
literal|'v'
block|,
literal|'w'
block|,
literal|'x'
block|,
literal|'p'
block|,
comment|/* u,v,w,x,y */
literal|'p'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Brodersen EECS VLSI VAX (VLSI) */
end_comment

begin_decl_stmt
name|char
name|configL
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'m'
block|,
literal|'m'
block|,
literal|'m'
block|,
literal|'m'
block|,
literal|'m'
block|,
comment|/* a,b,c,d,e */
literal|'m'
block|,
literal|'m'
block|,
literal|000
block|,
literal|'m'
block|,
literal|'m'
block|,
comment|/* f,g,h,i,j */
literal|'m'
block|,
literal|'l'
block|,
literal|'m'
block|,
literal|'m'
block|,
literal|'m'
block|,
comment|/* k,l,m,n,o */
literal|'m'
block|,
literal|'m'
block|,
literal|'m'
block|,
literal|'m'
block|,
literal|'m'
block|,
comment|/* p,q,r,s,t */
literal|'m'
block|,
literal|'m'
block|,
literal|'m'
block|,
literal|'m'
block|,
literal|'m'
block|,
comment|/* u,v,w,x,y */
literal|'m'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sakrison's Image Project 11/40 (Image) */
end_comment

begin_decl_stmt
name|char
name|configM
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
comment|/* a,b,c,d,e */
literal|'o'
block|,
literal|'o'
block|,
literal|000
block|,
literal|'o'
block|,
literal|'o'
block|,
comment|/* f,g,h,i,j */
literal|'o'
block|,
literal|'l'
block|,
literal|'m'
block|,
literal|'o'
block|,
literal|'o'
block|,
comment|/* k,l,m,n,o */
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
comment|/* p,q,r,s,t */
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
comment|/* u,v,w,x,y */
literal|'o'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fatemans Applied Math VAX (Kim) */
end_comment

begin_decl_stmt
name|char
name|configN
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* a,b,c,d,e */
literal|'k'
block|,
literal|'k'
block|,
literal|000
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* f,g,h,i,j */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'n'
block|,
literal|'k'
block|,
comment|/* k,l,m,n,o */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* p,q,r,s,t */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* u,v,w,x,y */
literal|'k'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pfeister - Pollack - Sangiovanni Optimization VAX (ESVAX) */
end_comment

begin_decl_stmt
name|char
name|configO
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'p'
block|,
literal|'y'
block|,
comment|/* a,b,c,d,e */
literal|'g'
block|,
literal|'g'
block|,
literal|000
block|,
literal|'p'
block|,
literal|'p'
block|,
comment|/* f,g,h,i,j */
literal|'p'
block|,
literal|'m'
block|,
literal|'m'
block|,
literal|'p'
block|,
literal|'o'
block|,
comment|/* k,l,m,n,o */
literal|'p'
block|,
literal|'y'
block|,
literal|'p'
block|,
literal|'y'
block|,
literal|'y'
block|,
comment|/* p,q,r,s,t */
literal|'p'
block|,
literal|'p'
block|,
literal|'p'
block|,
literal|'p'
block|,
literal|'y'
block|,
comment|/* u,v,w,x,y */
literal|'z'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Newton's CAD machine (VAX 11/780) */
end_comment

begin_decl_stmt
name|char
name|configP
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* a,b,c,d,e */
literal|'k'
block|,
literal|'k'
block|,
literal|000
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* f,g,h,i,j */
literal|'k'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'k'
block|,
literal|'o'
block|,
comment|/* k,l,m,n,o */
literal|'p'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'o'
block|,
comment|/* p,q,r,s,t */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'o'
block|,
comment|/* u,v,w,x,y */
literal|'o'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Computer Center Q Machine (Q) */
end_comment

begin_decl_stmt
name|char
name|configQ
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
comment|/* a,b,c,d,e */
literal|'e'
block|,
literal|'e'
block|,
literal|000
block|,
literal|'e'
block|,
literal|'e'
block|,
comment|/* f,g,h,i,j */
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
comment|/* k,l,m,n,o */
literal|'e'
block|,
literal|'q'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
comment|/* p,q,r,s,t */
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
comment|/* u,v,w,x,y */
literal|'e'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fabry's ARPA support VAX - ARPAVAX */
end_comment

begin_decl_stmt
name|char
name|configR
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* a,b,c,d,e */
literal|'k'
block|,
literal|'k'
block|,
literal|000
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* f,g,h,i,j */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* k,l,m,n,o */
literal|'k'
block|,
literal|'k'
block|,
literal|'r'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* p,q,r,s,t */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* u,v,w,x,y */
literal|'k'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Survey Research Center 11/40 (SRC) */
end_comment

begin_decl_stmt
name|char
name|configS
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
comment|/* a,b,c,d,e */
literal|'e'
block|,
literal|'e'
block|,
literal|000
block|,
literal|'e'
block|,
literal|'e'
block|,
comment|/* f,g,h,i,j */
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
comment|/* k,l,m,n,o */
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'s'
block|,
literal|'e'
block|,
comment|/* p,q,r,s,t */
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'e'
block|,
comment|/* u,v,w,x,y */
literal|'e'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Math-Stat Departement machine 11-45 (MathStat) */
end_comment

begin_decl_stmt
name|char
name|configT
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
comment|/* a,b,c,d,e */
literal|'y'
block|,
literal|'y'
block|,
literal|000
block|,
literal|'y'
block|,
literal|'y'
block|,
comment|/* f,g,h,i,j */
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
comment|/* k,l,m,n,o */
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'t'
block|,
comment|/* p,q,r,s,t */
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
comment|/* u,v,w,x,y */
literal|'y'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ARPANET gateway (ucbc70) */
end_comment

begin_decl_stmt
name|char
name|configU
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* a,b,c,d,e */
literal|'k'
block|,
literal|'k'
block|,
literal|000
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* f,g,h,i,j */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* k,l,m,n,o */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* p,q,r,s,t */
literal|'u'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* u,v,w,x,p */
literal|'k'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EECS Research (Fateman - Ernie) VAX (CSVAX) */
end_comment

begin_decl_stmt
name|char
name|configV
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* a,b,c,d,e */
literal|'k'
block|,
literal|'k'
block|,
literal|000
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* f,g,h,i,j */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* k,l,m,n,o */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* p,q,r,s,t */
literal|'k'
block|,
literal|'v'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* u,v,w,x,p */
literal|'k'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Statistics VAX 11/780 (ucbstatvax) */
end_comment

begin_decl_stmt
name|char
name|configW
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* a,b,c,d,e */
literal|'k'
block|,
literal|'k'
block|,
literal|000
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* f,g,h,i,j */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* k,l,m,n,o */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* p,q,r,s,t */
literal|'k'
block|,
literal|'k'
block|,
literal|'w'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* u,v,w,x,p */
literal|'k'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CS Research Onyx Computer */
end_comment

begin_decl_stmt
name|char
name|configX
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* a,b,c,d,e */
literal|'k'
block|,
literal|'k'
block|,
literal|000
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* f,g,h,i,j */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* k,l,m,n,o */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
comment|/* p,q,r,s,t */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'x'
block|,
literal|'k'
block|,
comment|/* u,v,w,x,y */
literal|'k'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EECS Instructional 11/70 (199 Cory) (Cory) */
end_comment

begin_decl_stmt
name|char
name|configY
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* a,b,c,d,e */
literal|'c'
block|,
literal|'c'
block|,
literal|000
block|,
literal|'o'
block|,
literal|'o'
block|,
comment|/* f,g,h,i,j */
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
comment|/* k,l,m,n,o */
literal|'o'
block|,
literal|'c'
block|,
literal|'o'
block|,
literal|'c'
block|,
literal|'t'
block|,
comment|/* p,q,r,s,t */
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'y'
block|,
comment|/* u,v,w,x,y */
literal|'o'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EECS Departmental 11/40  (EECS40) */
end_comment

begin_decl_stmt
name|char
name|configZ
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
comment|/* a,b,c,d,e */
literal|'o'
block|,
literal|'o'
block|,
literal|000
block|,
literal|'o'
block|,
literal|'o'
block|,
comment|/* f,g,h,i,j */
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
comment|/* k,l,m,n,o */
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
comment|/* p,q,r,s,t */
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
comment|/* u,v,w,x,y */
literal|'z'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if machtype is 	M_CC		netlpr will do lpr w/o an acct. 			Will pre-encrypt the password. 	M_INGRES	will allow higher file lengths. 	M_OTHER		will give no unusual effects. (when in doubt, machtype should be M_OTHER) */
end_comment

begin_decl_stmt
name|char
name|machtype
index|[]
init|=
block|{
name|M_CC
block|,
name|M_CC
block|,
name|M_CC
block|,
name|M_CC
block|,
name|M_CC
block|,
comment|/* a,b,c,d,e */
name|M_CC
block|,
name|M_CC
block|,
literal|0
block|,
name|M_INGRES
block|,
name|M_INGRES
block|,
comment|/* f,g,h,i,j */
name|M_OTHER
block|,
name|M_OTHER
block|,
name|M_OTHER
block|,
name|M_OTHER
block|,
name|M_OTHER
block|,
comment|/* k,l,m,n,o */
name|M_OTHER
block|,
name|M_OTHER
block|,
name|M_OTHER
block|,
name|M_OTHER
block|,
name|M_OTHER
block|,
comment|/* p,q,r,s,t */
name|M_OTHER
block|,
name|M_OTHER
block|,
name|M_OTHER
block|,
name|M_OTHER
block|,
name|M_OTHER
block|,
comment|/* u,v,w,x,y */
name|M_OTHER
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* z */
end_comment

begin_comment
comment|/* this is basically the default machine for each local machine */
end_comment

begin_decl_stmt
name|char
name|remtable
index|[]
init|=
block|{
literal|'c'
block|,
literal|'e'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'c'
block|,
comment|/* a,b,c,d,e */
literal|'g'
block|,
literal|'k'
block|,
literal|000
block|,
literal|'j'
block|,
literal|'k'
block|,
comment|/* f,g,h,i,j */
literal|'v'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'k'
block|,
literal|'p'
block|,
comment|/* k,l,m,n,o */
literal|'k'
block|,
literal|'e'
block|,
literal|'k'
block|,
literal|'e'
block|,
literal|'y'
block|,
comment|/* p,q,r,s,t */
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'o'
block|,
comment|/* u,v,w,x,y */
literal|'o'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bad login names */
end_comment

begin_decl_stmt
name|struct
name|bstruct
name|btable
index|[]
init|=
block|{
literal|"op"
block|,
literal|'a'
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this table shows the correspondence between    machine names like 'Cory' and their internal names, like 'y' */
end_comment

begin_struct
specifier|static
struct|struct
name|tt
block|{
name|char
modifier|*
name|bigname
decl_stmt|;
name|char
name|lname
decl_stmt|;
block|}
name|table
index|[]
init|=
block|{
literal|"A"
block|,
literal|'a'
block|,
literal|"ucbcfo-a"
block|,
literal|'a'
block|,
literal|"B"
block|,
literal|'b'
block|,
literal|"ucbcfo-b"
block|,
literal|'b'
block|,
literal|"C"
block|,
literal|'c'
block|,
literal|"ucbcfo-c"
block|,
literal|'c'
block|,
literal|"D"
block|,
literal|'d'
block|,
literal|"ucbcfo-d"
block|,
literal|'d'
block|,
literal|"E"
block|,
literal|'e'
block|,
literal|"ucbcfo-e"
block|,
literal|'e'
block|,
literal|"F"
block|,
literal|'f'
block|,
literal|"ucbcfo-f"
block|,
literal|'f'
block|,
literal|"G"
block|,
literal|'g'
block|,
literal|"ucbcfo-g"
block|,
literal|'g'
block|,
literal|"H"
block|,
literal|'h'
block|,
literal|"ucbcfo-h"
block|,
literal|'h'
block|,
literal|"Ing70"
block|,
literal|'i'
block|,
literal|"ucbing70"
block|,
literal|'i'
block|,
literal|"IngVAX"
block|,
literal|'j'
block|,
literal|"ucbingres"
block|,
literal|'j'
block|,
literal|"ucbvax"
block|,
literal|'k'
block|,
literal|"UCBVAX"
block|,
literal|'k'
block|,
literal|"VLSI"
block|,
literal|'l'
block|,
literal|"ucbvlsi"
block|,
literal|'l'
block|,
literal|"Image"
block|,
literal|'m'
block|,
literal|"ucbimage"
block|,
literal|'m'
block|,
literal|"Kim"
block|,
literal|'n'
block|,
literal|"ucbkim"
block|,
literal|'n'
block|,
literal|"ESVAX"
block|,
literal|'o'
block|,
literal|"ucbopt"
block|,
literal|'o'
block|,
literal|"CAD"
block|,
literal|'p'
block|,
literal|"ucbcad"
block|,
literal|'p'
block|,
literal|"Q"
block|,
literal|'q'
block|,
literal|"ucbcfo-q"
block|,
literal|'q'
block|,
literal|"ARPAVAX"
block|,
literal|'r'
block|,
literal|"ucbarpa"
block|,
literal|'r'
block|,
literal|"SRC"
block|,
literal|'s'
block|,
literal|"ucbsrc"
block|,
literal|'s'
block|,
literal|"MathStat"
block|,
literal|'t'
block|,
literal|"ucbmathstat"
block|,
literal|'t'
block|,
literal|"C70"
block|,
literal|'u'
block|,
literal|"ucbc70"
block|,
literal|'u'
block|,
literal|"CSVAX"
block|,
literal|'v'
block|,
literal|"ucbernie"
block|,
literal|'v'
block|,
literal|"ucbstatvax"
block|,
literal|'w'
block|,
literal|"StatVax"
block|,
literal|'w'
block|,
literal|"ucbonyx"
block|,
literal|'x'
block|,
literal|"Onyx"
block|,
literal|'x'
block|,
literal|"Cory"
block|,
literal|'y'
block|,
literal|"ucbcory"
block|,
literal|'y'
block|,
literal|"EECS40"
block|,
literal|'z'
block|,
literal|"ucbeecs40"
block|,
literal|'z'
block|,
literal|0
block|,
literal|0
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

