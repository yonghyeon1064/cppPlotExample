Graph Plotting in CPP
=====================


.. contents:: **Table of Contents**
    :backlinks: top
    :local:
    
    
    
Requirements
------------

I did the plotting in C++ using ``pbPlot``, which is an external module. If you want to plot the graph in C++ with **pbPlot**, you should download the ``.cpp`` and ``.hpp`` files from the below link. 

``pbPlot``이라는 외부 모듈을 이용해서 C++에서 그래프를 그리는 방법을 알려드립니다. C++에서도 그래프를 그리는 여러방법이 있지만, 현재는 pbPlot 모듈을 이요했습니다. 이때, ``.cpp`` 와 ``.hpp``파일이 중요한데, 아래의 링크에서 다운로드를 해주세요.

**CAUTION: You should download the files, which have the following names, in 'Raw' and 'Save link as'.**
**주의: 아래의 칸에 적힌 이름들을 가진 파일들을 'Raw'와 'Save Link as'를 통해 다운로드해주세요.**

.. code::

    pbPlots.cpp
    pbPlots.hpp
    support.cpp
    support.hpp
    
..

    https://github.com/InductiveComputerScience/pbPlots/tree/master/Cpp

Example Codes
-------------

.. code:: cpp

  #include "pbPlots.hpp"
  #include "supportLib.hpp"

  std::vector<double> createDomain(const double start, const double end, const double step);
  std::vector<double> sin_func(const std::vector<double> domain);
  
  
  
  int main()
  {
      RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();

      //std::vector<double> x = {-2, -1, 0, 1, 2};
      //std::vector<double> y = {1, 2, 3, 4, 5};

      std::vector<double> x = createDomain(-5, 5, 0.1);
      std::vector<double> y = sin_func(x);

      DrawScatterPlot(imageReference, 1000, 1000, &x, &y);

      std::vector<double> *pngData = ConvertToPNG(imageReference->image);
      WriteToFile(pngData, "basic.png");
      DeleteImage(imageReference->image);

      return 0;
  }


  std::vector<double> createDomain(const double start, const double end, const double step){
      std::vector<double> domain;
      for(double i=start; i<end; i += step){
          domain.push_back(i);
      }
      return domain;
  }

  std::vector<double> sin_func(const std::vector<double> domain){
      std::vector<double> range;
      for (int i=0; i<domain.size(); ++i){
          range.push_back(sin(domain[i]));
      }
      return range;
  }




Execution Command
-----------------

You can compile the cpp file and execute the compiled file using the below commands.

.. code:: shell

  g++ -o demo.out main.cpp pbPlots.cpp supportLib.cpp -lm
  ./demo.out
  
  
**If you use a shell script**

After you enter the commands in shell script file, execute the below commands **when you save the shell script file as** ``do.sh``.

.. code:: shell

    sh do.sh
