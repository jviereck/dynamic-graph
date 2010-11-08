/*
 * Copyright 2010,
 * François Bleibel,
 * Olivier Stasse,
 *
 * CNRS/AIST
 *
 * This file is part of dynamic-graph.
 * dynamic-graph is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 * dynamic-graph is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.  You should
 * have received a copy of the GNU Lesser General Public License along
 * with dynamic-graph.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __TRACER_RT_H__
#define __TRACER_RT_H__

/* --------------------------------------------------------------------- */
/* --- INCLUDE --------------------------------------------------------- */
/* --------------------------------------------------------------------- */

/* STD */
#include <sstream>

/* DG */
#include <dynamic-graph/tracer.h>
#include <dynamic-graph/config-tracer-real-time.hh>

/* --------------------------------------------------------------------- */
/* --- TRACER ---------------------------------------------------------- */
/* --------------------------------------------------------------------- */

namespace dynamicgraph {

class DG_TRACERREALTIME_DLLAPI OutStringStream
  : public std::ostringstream
{
public:
  char * buffer;
  size_t index;
  size_t bufferSize;
  bool full;
  std::string givenname;

public:

  OutStringStream( void );
  ~OutStringStream( void );

  void resize( const unsigned int & size );
  bool addData( const char * data, const std::streamoff& size );
  void dump( std::ostream& os );
  void empty( void );

};

class DG_TRACERREALTIME_DLLAPI TracerRealTime
: public Tracer
{
 public:
  static const std::string CLASS_NAME;
  virtual const std::string& getClassName( void ) { return CLASS_NAME; }

 protected:
  int bufferSize;
  static const int BUFFER_SIZE_DEFAULT = 1048576; //  1Mo
  typedef std::list< std::ofstream* > HardFileList;
  HardFileList hardFiles;

 public:
  TracerRealTime( const std::string n );
  virtual ~TracerRealTime( void ){ }

 public:
  virtual void closeFiles( void );
  virtual void trace( void );
 protected:
  virtual void openFile( const SignalBase<int> & sig,
			 const std::string& filename );
  virtual void recordSignal( std::ostream& os,
			     const SignalBase<int>& sig );
  void emptyBuffers( void );

 public:
  void setBufferSize( const int & SIZE ) { bufferSize=SIZE; }
  const int & getBufferSize( void ) { return bufferSize; }

 public:

  /* --- DISPLAY ------------------------------------------------------------ */
  void display( std::ostream& os ) const;
  DG_TRACERREALTIME_DLLAPI friend std::ostream& operator<<
    (std::ostream& os, const TracerRealTime& t);

  /* --- PARAMS --- */
  virtual void commandLine( const std::string& cmdLine
			    ,std::istringstream& cmdArgs
			    ,std::ostream& os );
};


} // namespace dynamicgraph


#endif /* #ifndef __TRACER_RT_H__ */
