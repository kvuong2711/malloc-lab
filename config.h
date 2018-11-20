#ifndef __CONFIG_H_
#define __CONFIG_H_

/*
 * config.h - malloc lab configuration file
 *
 * Copyright (c) 2002, R. Bryant and D. O'Hallaron, All rights reserved.
 * May not be used, modified, or copied without permission.
 */

/*
 * This is the default path where the driver will look for the
 * default tracefiles. You can override it at runtime with the -t flag.
 */
#define TRACEDIR "/web/classes/Fall-2018/csci2021-010/ha/4/traces/"

/*
 * This is the list of default tracefiles in TRACEDIR that the driver
 * will use for testing. Modify this if you want to add or delete
 * traces from the driver's test suite. For example, if you don't want
 * your students to implement realloc, you can delete the last two
 * traces.
 */
#define DEFAULT_TRACEFILES \
  "amptjp-bal.rep",\
  "cccp-bal.rep",\
  "cp-decl-bal.rep",\
  "expr-bal.rep",\
  "coalescing-bal.rep",\
  "random-bal.rep",\
  "random2-bal.rep",\
/*  "binary-bal.rep",*/ \
/*  "binary2-bal.rep",*/ \
  "realloc-bal.rep",\
  "realloc2-bal.rep"

/*
 * This constant gives the estimated performance of the libc malloc
 * package using our traces on some reference system, typically the
 * same kind of system the students use. Its purpose is to cap the
 * contribution of throughput to the performance index. Once the
 * students surpass the AVG_LIBC_THRUPUT, they get no further benefit
 * to their score.  This deters students from building extremely fast,
 * but extremely stupid malloc packages.
 */
/* 20965e3 is glibc 2.27 (Ubuntu 18.04) on a Core i7-4790. */
/* This is quite achievable, and getting this throughput together with
   high utilization is more difficult but still possible. However
   performance is quite machine-dependent, so we use Callgrind for
   grading. */
#define AVG_LIBC_THRUPUT      20965e3  /* 20965 Kops/sec */

 /*
  * These constants control how space utilization and throughput are
  * converted into integer scores. We don't require that they add to
  * 100, to allow room for other parts of the final score.
  */
#define UTIL_POINTS 40
#define THRU_POINTS 40

/*
 * Alignment requirement in bytes (either word size or 2 * word size)
 */
#define ALIGNMENT 16

/*
 * Maximum heap size in bytes
 */
#define MAX_HEAP (40L*(1<<20))  /* 40 MB; about 1500MB is needed for naive */

/*****************************************************************************
 * Set exactly one of these USE_xxx constants to "1" to select a timing method
 *****************************************************************************/
#define USE_FCYC   0   /* cycle counter w/K-best scheme (x86 & Alpha only) */
#define USE_ITIMER 0   /* interval timer (any Unix box) */
#define USE_GETTOD 1   /* gettimeofday (any Unix box) */

/* USE_CALLGRIND can be set independently of any of the above USE_
   methods, since it's still optional when available. */
#define USE_CALLGRIND 1

#endif /* __CONFIG_H */
