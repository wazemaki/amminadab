#include <QApplication>
#include <iostream>
#include <string>
#include <sstream>
#include <signal.h>
#include "samu.hpp"
//#include "samugui.h"

Samu samu {"Nahshon", "samu.soul.txt"};

bool halted {false};

void save_samu ( int sig )
{
  if ( halted )
    return;
  halted = true;

#ifndef Q_LOOKUP_TABLE
  samu.save ();
#endif

  samu.halt();
  //exit ( 0 );
}

double to_samu ( int channel, SPOTriplets &tv )
{
  double r {0.0};

  try
    {
      samu.triplet ( channel, tv );
      r = samu.reward();
    }
  catch ( const char* err )
    {
      std::cerr << err << std::endl;
    }
  return r;
}


double to_samu ( int channel, std::string &msg )
{
  double r {0.0};

  try
    {
      samu.sentence ( channel, msg );
      r = samu.reward();
    }
  catch ( const char* err )
    {
      std::cerr << err << std::endl;
    }
  return r;
}

double to_samu ( int channel, std::string &msg, std::string &key )
{
  double r {0.0};

  try
    {
      samu.sentence ( channel, msg, key );
      r = samu.reward();
    }
  catch ( const char* err )
    {
      std::cerr << err << std::endl;
    }
  return r;
}

std::map<std::string, SPOTriplets> cache;

int samuHasAlreadyLearned {7};
int reinforcement {0};

double read_cache ( std::string & key, int &cnt, int &brel )
{
  double sum {0.0};
  int count {0};
  for ( auto const & t: cache[key] )
    {
      if ( !samu.sleep() )
        break;

      if ( count++ >= samuHasAlreadyLearned )
        break;

      SPOTriplets tv;
      tv.push_back ( t );
      sum += to_samu ( 12, tv );
      ++cnt;
      brel += samu.get_brel();
    }

  return sum;
}
void MyThread::run(){

    /*
     #ifndef Q_LOOKUP_TABLE
       std::string samuImage {"samu.soul.txt"};

       std::fstream samuFile ( samuImage,  std::ios_base::in );
       if ( samuFile )
         samu.load ( samuFile );
     #endif
     */

     struct sigaction sa;
     sa.sa_handler = save_samu;
     sigemptyset ( &sa.sa_mask );
     sa.sa_flags = SA_RESTART;

     sigaction ( SIGINT, &sa, NULL );
     sigaction ( SIGTERM, &sa, NULL );
     sigaction ( SIGKILL, &sa, NULL );
     sigaction ( SIGHUP, &sa, NULL );

     // Do not remove this copyright notice!
     std::cerr << "This program is "
               << samu.get_name()
               << ", the son of Samu Bátfai."
               << std::endl
               << "Copyright (C) 2015 Norbert Bátfai"
               << std::endl
               << "License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>"
               << std::endl
               << "This is free software: you are free to change and redistribute it."
               << std::endl
               << "There is NO WARRANTY, to the extent permitted by law."
               << std::endl
               << std::endl;


     std::map<std::string, std::vector<std::string>> tests
     {
       {
         "sentences of the paper [1]",
         {
           "A rare black squirrel has become a regular visitor to a suburban garden",
           "This is a car",
           "This car is mine",
           "I have a little car",
           "The sky is blue",
           "The little brown bear has eaten all of the honey",
           "I love Samu"
         }
       },
       {
         "introduce myself",
         {
           "Who are you",
           "I am a robot",
           "What is your name",
           "My name is Judah",
           "Where do you live",
           "I live in Debrecen",
           "How old are you",
           "I am one year old",
           "Where were you born"
           "I was born is Debrecen"
           "What is your favourite colour"
           "My favourite colours are red, white and green"
         }
       }
     };

     std::map<std::string, SPOTriplets> test_triplets
     {
       {
         "introduce myself",
         {
           { "who", "are", "you" },
           { "i", "am", "robot"  },
           {"what",  "is",  "name"},
           {"name", "is", "Judah"},
           {"you", "live", "where"},
           {"I", "live", "Debrecen"},
           {"you", "are", "how"},
           {"i", "am", "one"},
           {"you", "born", "where"},
           {"I", "born", "Debrecen"}
         }
       }
     };


     int j {0};
     int N_e {20};
     std::string training_file = samu.get_training_file();

     samu.set_training_file ( "be.txt" );

     double prev_mbrel {0};
     int mbrelc {0};
     int mbrelc2 {0};
     int prev_bad {0};

   #ifdef SUPER_OR_REMOTE_COMP
     //for ( int ii {0}; samu.run() && ii < 1000 + 4000 + 5000 + 4000 + 1000; ++ii )
     for ( int ii {0}; samu.run() /*&& ii < 50000*/; ++ii )
   #else
     for ( ; samu.run(); )
       //for ( int ii {0}; samu.run() && ii < 50; ++ii )
   #endif
       {
         auto start = std::chrono::high_resolution_clock::now();
         double sum {0.0};
         int cnt {0};
         int brel {0};
         if ( samu.sleep() )
           {

   #ifdef SUPER_OR_REMOTE_COMP
             /*
                       if ( ii == 1 )
                         {
                           std::cerr << " iter, training file changed " << std::endl;
                           samu.set_training_file ( "bbe" );
                         }
                       else if ( ii == 3 )
                         {
                           std::cerr << " iter, training file changed " << std::endl;
                           training_file = "bbe";
                         }
             */
             /*
                   if ( ii == 1000 )
                     {
                       std::cerr << " iter, training file changed " << std::endl;
                       samu.set_training_file ( "bbe" );
                     }
                   else if ( ii == 1000 + 4000 )
                     {
                       std::cerr << " iter, training file changed " << std::endl;
                       training_file = "none";
                       samu.set_training_file ( training_file );
                     }
                   else if ( ii == 1000 + 4000 + 5000 )
                     {
                       std::cerr << " iter, training file changed " << std::endl;
                       samu.set_training_file ( "bbe" );
                     }
                   else if ( ii == 1000 + 4000 + 5000 + 4000 )
                     {
                       std::cerr << " iter, training file changed " << std::endl;
                       training_file = "none";
                       samu.set_training_file ( training_file );
                     }
                     */
   #endif

             samu.clear_vi();
             if ( samu.get_training_file() == training_file )
               {
                 samu.set_N_e ( N_e );
                 for ( int i {0}; i<test_triplets["introduce myself"].size() && samu.sleep(); ++i )
                   {
                     SPOTriplets tv;
                     tv.push_back ( test_triplets["introduce myself"][i] );
                     sum += to_samu ( 11, tv );
                     ++cnt;
                     brel += samu.get_brel();
                   }
               }
             else
               {
                 samu.set_N_e ( N_e );
                 std::string key = samu.get_training_file();

                 if ( cache.find ( key ) == cache.end() )
                   {

                     std::fstream triplet_train ( key+".triplets",  std::ios_base::in );
                     if ( triplet_train )
                       {

                         do
                           {

                             SPOTriplet t;
                             triplet_train >> t;

                             if ( !t.empty() )
                               cache[key].push_back ( t );

                           }
                         while ( !triplet_train.eof() && samu.sleep() );

                         triplet_train.close();

                         std::cout<<key<<" "<< cnt <<" "<< brel <<std::endl;
                         sum = read_cache ( key, cnt, brel );

                       }
                     else
                       {

                         std::fstream train ( samu.get_training_file(),  std::ios_base::in );
                         if ( train )
                           {
                             std::string file = key+".triplets";
                             for ( std::string line; std::getline ( train, line ) && samu.sleep(); )
                               {

   #ifndef TRIPLET_CACHE
                                 sum += to_samu ( 12, line );
   #else
                                 sum += to_samu ( 12, line, file );
   #endif
                                 ++cnt;
                                 brel += samu.get_brel();

                               }
                             train.close();
                           }

                       }

                   }
                 else
                   {
                     sum = read_cache ( key, cnt, brel );

                   }

               }

             //std::cerr << "###### " << ++j << "-th iter " << sum << std::endl;

             double mbrel = ( double ) brel/ ( double ) cnt;
             int bad = ( sum - samu.get_max_reward() * cnt ) / ( samu.get_min_reward() - samu.get_max_reward() );
             std::cerr << ++j
                       << "-th iter, err: "
                       << cnt*samu.get_max_reward() - sum
                       << " ("
                       << sum
                       << ", good: "
                       << ( cnt-bad )
                       << ", bad: "
                       << bad
                       << "), brel%: "
                       << mbrel
                       << ", "
                       << std::chrono::duration_cast<std::chrono::milliseconds> ( std::chrono::high_resolution_clock::now() - start ).count()
                       << " ms "
                       << N_e
                       << std::endl;

             /*
               //if ( fabs ( prev_mbrel - mbrel ) < 1.2 )
               if ( mbrel  < 0.0 )
                 ++mbrelc;
               else
                 mbrelc = 0;

               if ( fabs ( prev_mbrel - mbrel ) < 2.0 )
                 ++mbrelc2;
               else
                 mbrelc2 = 0;
             */

             if ( fabs ( prev_mbrel - mbrel ) < 1.0 && prev_bad == bad )
               ++mbrelc;
             else
               mbrelc = 0;

             prev_bad = bad;

             /*
                       if ( fabs ( prev_mbrel - mbrel ) < .2 )
                         ++mbrelc2;
                       else
                         mbrelc2 = 0;
             */
             /*
                       if ( bad <= 3 )
                         {

                           if ( ++reinforcement == 20 )
                             {
                               samuHasAlreadyLearned += 7;
                               reinforcement = 0;
                             }
                         }
                       else if ( mbrelc2 >= 2*samuHasAlreadyLearned )
                         {

                           if ( N_e < samuHasAlreadyLearned )
                             N_e +=1;
                           samu.scale_N_e ( .75 );
                           mbrelc2 = 0;
                           std::cerr << "(mbrelc2) iter, N structure rescaled " << std::endl;

                         }
                       else if ( mbrelc > 2*samuHasAlreadyLearned && bad > 3 )
                         {

                           if ( N_e >samuHasAlreadyLearned )
                             N_e -=1;

                           samu.scale_N_e ( .82 );
                           //N_e += 5;
                           mbrelc = 0;
                           std::cerr << " iter, N structure rescaled " << std::endl;

                           //} else if(!bad)
                           //} else if(bad <cnt/10)
                         }
             */

             if ( /*mbrel > 35.0 &&*/ mbrelc > 20 && bad >=2 )
               {
                 samu.scale_N_e();
                 //N_e += 5;
                 mbrelc = 0;
                 std::cerr << " iter, N structure rescaled " << std::endl;

                 //} else if(!bad)
               }
             else if ( bad <2 )
               {
                 if ( ++reinforcement == 10 )
                   {
                     samuHasAlreadyLearned += 7;
                     reinforcement = 0;
                     samu.debug_tree();
                   }
               }


             //if ( /*mbrel > 35.0 &&*/ mbrelc > 50 && cnt-bad <= cnt- ( cnt/10 ) )
             /*if ( mbrelc > samuHasAlreadyLearned && bad >= 3 )
               {
                 //samu.scale_N_e(.92);


             //N_e += 1;

                 //samu.scale_N_e(.6);
                 //mbrelc = 0;
                 //std::cerr << " iter, N structure rescaled " << std::endl;

                 //} else if(!bad)
                 //} else if(bad <cnt/10)
               }
             else */
             /*if ( mbrelc2 >= samuHasAlreadyLearned )
                     {

                                     if(N_e < samuHasAlreadyLearned)
                 N_e +=1;
                       samu.scale_N_e(.67);
                 mbrelc2 = 0;
                       std::cerr << "(mbrelc2) iter, N structure rescaled " << std::endl;

                     }
                   else if ( bad < 3 )
                     {

                       if ( ++reinforcement == 10 )
                         {
                           samuHasAlreadyLearned += 7;
                           reinforcement = 0;
                         }
                     }
             */
             prev_mbrel = mbrel;

           }
         else
           sleep ( 1 );
       }

}

void SamuGUI::on_pushButton_2_clicked()
{
    mThread->terminate();

    while(!mThread->isFinished()){}
    save_samu(0);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SamuGUI w;
    w.show();
    samu.wpointer= &w;
    a.exec();
    w.mThread->terminate();
    while(!w.mThread->isFinished()){ }
    save_samu(0);
    return 0;
}
