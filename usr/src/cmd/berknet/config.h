begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	These are machine-configuration dependent 	tables.  To add a machine, be sure to update all 	these tables, add the "ifdef" entry in "mach.h", 	and add config? to gothru() in sub.c. 	For Berkeley, this file corresponds to the following network:  	IngVAX          ARPA 	  |		 |    Onyx 	  |		 |     / 	  |		 |    / 	  |		 |   / 	Ing70-----------CSVAX		A              B 	   		 |		|              | 	   		 |		|              | 	   		 |		|              | 	   		 |		|              | 	MathStat--------Cory------------C--------------D------------F 			 |		|	       | 			 |		|	       | 			 |		|	       | 			 |		|	       | 	EECS40----------ESVAX		E	      SRC 	   		 |	       /| 	   		 |     	      / |  	   		 |	     /	|   	   		 |	    /	|    	VLSI------------Image	 Virus	Q     	The tables must be consistent.   	For RAND, these tables are:  		VAX (C) ---------GRAPHICS (A)------- TP (B)  	For NOSC, these tables are:  		atts (a) ------- mssf (m) ---------- ccmm (c)  */
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
literal|'m'
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
literal|'m'
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
literal|'m'
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
literal|0
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
name|M_OTHER
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
literal|'a'
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
literal|"atts"
block|,
literal|'a'
block|,
literal|"ccmm"
block|,
literal|'c'
block|,
literal|"mssf"
block|,
literal|'m'
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
literal|000
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
literal|000
block|,
literal|'c'
block|,
comment|/* k,l,m,n,o */
literal|000
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
literal|000
block|,
literal|'c'
block|,
literal|000
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
literal|'d'
block|,
literal|'b'
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* a,b,c,d,e */
literal|'d'
block|,
literal|000
block|,
literal|000
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* f,g,h,i,j */
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|000
block|,
literal|'d'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* u,v,w,x,y */
literal|'d'
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
literal|'d'
block|,
literal|'c'
block|,
literal|'d'
block|,
literal|'e'
block|,
comment|/* a,b,c,d,e */
literal|'d'
block|,
literal|000
block|,
literal|000
block|,
literal|'y'
block|,
literal|'y'
block|,
comment|/* f,g,h,i,j */
literal|'e'
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|000
block|,
literal|'y'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'e'
block|,
literal|'y'
block|,
literal|'d'
block|,
literal|'e'
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'y'
block|,
literal|000
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
comment|/* Computer Center D Machine (D) */
end_comment

begin_decl_stmt
name|char
name|configD
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
literal|'d'
block|,
literal|'c'
block|,
comment|/* a,b,c,d,e */
literal|'f'
block|,
literal|000
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
literal|000
block|,
literal|'c'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'s'
block|,
literal|'c'
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'c'
block|,
literal|000
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
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'e'
block|,
comment|/* a,b,c,d,e */
literal|'c'
block|,
literal|000
block|,
literal|000
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* f,g,h,i,j */
literal|'k'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|000
block|,
literal|'c'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'q'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'t'
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'c'
block|,
literal|000
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
comment|/* Computer Center F Machine (F) */
end_comment

begin_decl_stmt
name|char
name|configF
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* a,b,c,d,e */
literal|'f'
block|,
literal|000
block|,
literal|000
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* f,g,h,i,j */
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|000
block|,
literal|'d'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* u,v,w,x,y */
literal|'d'
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
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
comment|/* a,b,c,d,e */
literal|'v'
block|,
literal|000
block|,
literal|000
block|,
literal|'i'
block|,
literal|'j'
block|,
comment|/* f,g,h,i,j */
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
literal|000
block|,
literal|'v'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'v'
block|,
literal|000
block|,
literal|'v'
block|,
literal|'v'
block|,
comment|/* u,v,w,x,y */
literal|'v'
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
literal|'i'
block|,
literal|'i'
block|,
literal|'i'
block|,
literal|'i'
block|,
literal|'i'
block|,
comment|/* a,b,c,d,e */
literal|'i'
block|,
literal|000
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
literal|'i'
block|,
literal|'i'
block|,
literal|000
block|,
literal|'i'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'i'
block|,
literal|'i'
block|,
literal|'i'
block|,
literal|'i'
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'i'
block|,
literal|000
block|,
literal|'i'
block|,
literal|'i'
block|,
comment|/* u,v,w,x,y */
literal|'i'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Biochemistry (Virus) PDP-11/40 Running V7 */
end_comment

begin_decl_stmt
name|char
name|configK
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
literal|000
block|,
literal|000
block|,
literal|'e'
block|,
literal|'e'
block|,
comment|/* f,g,h,i,j */
literal|'k'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|000
block|,
literal|'e'
block|,
comment|/* k,l,m,n,o */
literal|000
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
literal|000
block|,
literal|'e'
block|,
literal|000
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
comment|/* Brodersen-Newton VLSI-CAD VAX (VLSI) */
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
literal|000
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
literal|000
block|,
literal|'m'
block|,
comment|/* k,l,m,n,o */
literal|000
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
literal|000
block|,
literal|'m'
block|,
literal|000
block|,
literal|000
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
literal|000
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
literal|000
block|,
literal|'o'
block|,
comment|/* k,l,m,n,o */
literal|000
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
literal|000
block|,
literal|'o'
block|,
literal|000
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
literal|'y'
block|,
literal|'y'
block|,
comment|/* a,b,c,d,e */
literal|'y'
block|,
literal|000
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
literal|'m'
block|,
literal|'m'
block|,
literal|000
block|,
literal|'o'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'y'
block|,
literal|000
block|,
literal|'y'
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
literal|000
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
literal|000
block|,
literal|'e'
block|,
comment|/* k,l,m,n,o */
literal|000
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
literal|000
block|,
literal|'e'
block|,
literal|000
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
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
comment|/* a,b,c,d,e */
literal|'v'
block|,
literal|000
block|,
literal|000
block|,
literal|'v'
block|,
literal|'v'
block|,
comment|/* f,g,h,i,j */
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
literal|000
block|,
literal|'v'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'v'
block|,
literal|'r'
block|,
literal|'v'
block|,
literal|'v'
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'v'
block|,
literal|000
block|,
literal|'v'
block|,
literal|'v'
block|,
comment|/* u,v,w,x,y */
literal|'v'
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
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* a,b,c,d,e */
literal|'d'
block|,
literal|000
block|,
literal|000
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* f,g,h,i,j */
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|000
block|,
literal|'d'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'s'
block|,
literal|'d'
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* u,v,w,x,y */
literal|'d'
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
literal|000
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
literal|000
block|,
literal|'y'
block|,
comment|/* k,l,m,n,o */
literal|000
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
literal|000
block|,
literal|'y'
block|,
literal|000
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
comment|/* EECS Research (Fateman - Ernie) VAX (CSVAX) */
end_comment

begin_decl_stmt
name|char
name|configV
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
literal|000
block|,
literal|000
block|,
literal|'i'
block|,
literal|'i'
block|,
comment|/* f,g,h,i,j */
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|000
block|,
literal|'y'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'y'
block|,
literal|'r'
block|,
literal|'y'
block|,
literal|'y'
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'v'
block|,
literal|000
block|,
literal|'x'
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
comment|/* CS Research Onyx Computer */
end_comment

begin_decl_stmt
name|char
name|configX
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
comment|/* a,b,c,d,e */
literal|'v'
block|,
literal|000
block|,
literal|000
block|,
literal|'v'
block|,
literal|'v'
block|,
comment|/* f,g,h,i,j */
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
literal|000
block|,
literal|'v'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'v'
block|,
literal|000
block|,
literal|'x'
block|,
literal|'v'
block|,
comment|/* u,v,w,x,y */
literal|'v'
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
literal|000
block|,
literal|000
block|,
literal|'v'
block|,
literal|'v'
block|,
comment|/* f,g,h,i,j */
literal|'c'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|000
block|,
literal|'o'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'c'
block|,
literal|'v'
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'v'
block|,
literal|000
block|,
literal|'v'
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
literal|000
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
literal|000
block|,
literal|'o'
block|,
comment|/* k,l,m,n,o */
literal|000
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
literal|000
block|,
literal|'o'
block|,
literal|000
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
literal|0
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
literal|0
block|,
name|M_OTHER
block|,
comment|/* k,l,m,n,o */
literal|0
block|,
name|M_CC
block|,
name|M_OTHER
block|,
name|M_OTHER
block|,
name|M_OTHER
block|,
comment|/* p,q,r,s,t */
literal|0
block|,
name|M_OTHER
block|,
literal|0
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
literal|'d'
block|,
literal|'a'
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* a,b,c,d,e */
literal|'d'
block|,
literal|000
block|,
literal|000
block|,
literal|'j'
block|,
literal|'i'
block|,
comment|/* f,g,h,i,j */
literal|'e'
block|,
literal|'m'
block|,
literal|'o'
block|,
literal|000
block|,
literal|'v'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'e'
block|,
literal|'v'
block|,
literal|'d'
block|,
literal|'e'
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'y'
block|,
literal|000
block|,
literal|'v'
block|,
literal|'v'
block|,
comment|/* u,v,w,x,y */
literal|'i'
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
literal|"A"
block|,
literal|'a'
block|,
literal|"B"
block|,
literal|'b'
block|,
literal|"C"
block|,
literal|'c'
block|,
literal|"D"
block|,
literal|'d'
block|,
literal|"E"
block|,
literal|'e'
block|,
literal|"F"
block|,
literal|'f'
block|,
literal|"Ing70"
block|,
literal|'i'
block|,
literal|"Ingres"
block|,
literal|'i'
block|,
literal|"IngVAX"
block|,
literal|'j'
block|,
literal|"Virus"
block|,
literal|'k'
block|,
literal|"VLSI"
block|,
literal|'l'
block|,
literal|"Image"
block|,
literal|'m'
block|,
literal|"ESVAX"
block|,
literal|'o'
block|,
literal|"OptVAX"
block|,
literal|'o'
block|,
literal|"Q"
block|,
literal|'q'
block|,
literal|"ARPAVAX"
block|,
literal|'r'
block|,
literal|"SRC"
block|,
literal|'s'
block|,
literal|"MathStat"
block|,
literal|'t'
block|,
literal|"CSVAX"
block|,
literal|'v'
block|,
literal|"VAX"
block|,
literal|'v'
block|,
literal|"Onyx"
block|,
literal|'x'
block|,
literal|"Cory"
block|,
literal|'y'
block|,
literal|"EECS40"
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

