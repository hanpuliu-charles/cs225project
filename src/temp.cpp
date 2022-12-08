

// Didn't include damping yet? should we?
std::vector<float> powerIteration(std::vector<std::vector<float>> m, std::vector<float> v, int n) {
    size_t m_size = m.size(); // M should be square
    for (int times = 0; times < n; times++){
        // Repeat n times
        std::vector<float> temp(0.0, m_size);
        for (int row = 0; row < m_size; row++){
            float accumulator = 0.0;
            for (int row = 0; row < m_size; row++){
                accumulator += m[row][col] * v[col];
            }
            temp[row] = accumulator;

        }
        v = temp;
    }
    return v;
}

void normalizeMatrix(std::vector<std::vector<float>>& input ) {
    std::vector<float> denominator;
    for (size_t col = 0; col < input.size(); col++){
        float accumulator = 0;
        for (size_t row = 0; row < input.size(); row++){
            accumulator += input[row][col];
        }
        denominator.push_back(accumulator);
    }
    for (size_t row = 0; row < input.size(); row++{
        for (size_t col = 0; col < input.size(); col++){
            if (denominator[col != 0]){
                input[row][col] /= denominator[col];
            } else {
                input[row][col] = 1.0/(float)input.size();
            }

        }
    }
}

