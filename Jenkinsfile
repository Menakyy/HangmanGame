pipeline {
    agent any
    
    stages {
        stage('Prepare') {
            steps {
                script {
                    sh 'git submodule update --init --recursive'
                    sh 'mkdir -p build'
                    sh 'cmake -S . -B build/ -DBUILD_TESTING=True -DCLANG_TIDY=True -DENABLE_VALGRIND=True'
                }
            }
        }
        
        stage('Build') {
            steps {
                script {
                    sh 'cd build && make'
                }
            }
            post {
                success {
                    echo 'Build succeeded.'
                }
                failure {
                    echo 'Build failed.'
                }
            }
        }
        
        stage('Run Tests') {
            steps {
                script {
                    sh './build/bin/MyProjectTests'
                }
            }
        }
    }
}
