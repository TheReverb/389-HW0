#include <iostream>
#include <vector>
#include <random>
#include <iostream>
#include <chrono>

using namespace std;

vector<double> generate_random_list(int size, double bound)
{
  vector<double> rand_list;

  default_random_engine generator;
  uniform_real_distribution<double> distribution(-bound, bound);

  for (int i = 0; i < size; i++)
  {
  rand_list.push_back(distribution(generator));
  }
  return rand_list;
}


void update_coords(vector<double>& xs, vector<double>& ys, vector<double>& zs,
                  vector<double>&vx, vector<double>& vy, vector<double>& vz)
{
    for (uint i = 0; i < xs.size(); i++)
    {

      xs[i] = xs[i] + vx[i];
      ys[i] = ys[i] + vy[i];
      zs[i] = zs[i] + vz[i];

    }
}


int main(int argc, char** argv)
{

  if (argc != 3)
  {
    cout << "/* Required arguments: vector_length(N) and iterations_num(M) */" << '\n';
    return(-1);
  }

  int size = atoi(argv[1]);
  int iters = atoi(argv[2]);


  vector<double> xs = generate_random_list(size, 1000.);
  vector<double> ys = generate_random_list(size, 1000.);
  vector<double> zs = generate_random_list(size, 1000.);

  vector<double> vx = generate_random_list(size, 1.);
  vector<double> vy = generate_random_list(size, 1.);
  vector<double> vz = generate_random_list(size, 1.);


  auto t1 = chrono::high_resolution_clock::now();
  for (int i = 0; i < iters; i++){

    update_coords(xs, ys, zs, vx, vy, vz);

  }
  auto t2 = chrono::high_resolution_clock::now();

  chrono::duration<double> elapsed = t2-t1;

  // auto duration = chrono::duration_cast<chrono::microseconds>( t2 - t1 ).count();
  auto mean = (elapsed.count() * 1000000) / (size * iters);

  cout << size << '\t' << mean << '\n';


}
