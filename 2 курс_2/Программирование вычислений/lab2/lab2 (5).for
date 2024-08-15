        program main
        
        call input
        call output
        
        end
        
        subroutine input
        implicit none
 
        common/table/x_min,x_max,x_step,y_min,y_max,y_step
        
        real x_min,x_max,x_step
        real y_min,y_max,y_step
        integer err
        
        open(1,FILE = 'input.txt', STATUS = 'old', IOSTAT = err)
        
        if (err.NE.0) then
        print* ,'Error opening file'
        pause
        stop
        end if
        
        read(1,*, IOSTAT = err)x_min,x_max,x_step
        read(1,*, IOSTAT = err)y_min,y_max,y_step
        close(1)
        
        if (err.NE.0) then
            print* ,'Error reading input file'
            pause
            stop
         end if
        
        if (x_min.GT.x_max.OR.y_min.GT.y_max) then
            print*,'The minimum is greater than the maximum'
            pause
            stop
        end if
        
        if ((x_step.NE.0.AND.x_min.EQ.x_max).OR.
     *  (y_step.NE.0.AND.y_min.EQ.y_max)) then 
            print *,'Incorrect step'
            pause
            stop
            end if
            
        if ((x_step.EQ.0.AND.x_min.NE.x_max).OR.
     *  (y_step.EQ.0.AND.y_min.NE.y_max)) then 
            print *,'Incorrect range input'
            pause
            stop
            end if
            
         if (x_step.LT.0.OR.y_step.LT.0) then
            print*, 'Negative step'
            pause
            stop
        end if
               
        if (mod(x_min,90.).eq.0.and.mod(x_min/90,2.).ne.0.
     *      and.mod(x_max,90.).eq.0.
     *      and.mod(x_max/90,2.).ne.0.
     *      and.mod(x_step,180.).eq.0) then
            print*,'all given points are out of the func domain range'
            pause
            stop
        end if
        
        call is_invisible_step
        
        end
        
        subroutine is_invisible_step 
        implicit none 
        
        common/table/x_min,x_max,x_step,y_min,y_max,y_step
        
        real x_min,x_max,x_step,y_min,y_max,y_step
        character*11 x_exp_1,x_exp_2,y_exp_1,y_exp_2
        
        write(x_exp_1,'(e11.4)')x_min
        write(x_exp_2,'(e11.4)')x_min+x_step
        
        if(x_exp_1.eq.x_exp_2.and.x_step.ne.0) then
            print*, 'invisible step'
            pause
            stop
        end if
        
        write(y_exp_1,'(e11.4)')y_min
        write(y_exp_2,'(e11.4)')(y_min+y_step)
        
        if(y_exp_1.eq.y_exp_2.and.y_step.ne.0) then
            print*, 'invisible step'
            pause
            stop    
        end if 
        
        end
        
        subroutine output
        implicit none
        common/table/x_min,x_max,x_step,y_min,y_max,y_step
        real x_min,x_max,x_step
        real y_min,y_max,y_step
        real x,y,pi,degree,n,m
        integer i,j,k
        pi = 3.14159265
        degree = 180/pi
        open (2,FILE = 'output.txt')
        if (x_step.ne.0.and.y_step.ne.0) then
            n = (x_max-x_min)/x_step
            m = (y_max-y_min)/y_step
            if (n.ne.int(n)) then
                n = int(n) + 2
            else 
                n = n + 1
            end if
            if (m.ne.int(m)) then
                m = int(m) + 2
            else 
                m = m + 1
            end if
        else 
            n=1
            m=1
        end if
        write(2,'(a,$)')'y\x'
        write(2,'(7x,a,$)')' '
        x=x_min
        do i=1,n
            write(2,'(a,$)')' |'
            write(2,'(e11.4,$)')x
            x=x+x_step
            if (x.gt.x_max) x=x_max
        end do
        write(2,'(/,$)')
        do i=1,(n+1)
            write(2,'(a,$)')'-------------'
        end do
        write(2,'(/,$)')
        y=y_min
        do i=1,m
            write(2,'(e11.4,$)')y
            x=x_min
            do j=1,n
                write(2,'(a,$)')' |'
                if (mod(x,90.).eq.0.and.mod(x/90,2.).ne.0) then
                    write (2, '(4x,a,$)')'inf'
                    write (2,'(3x,a,$)')' '
                else 
                    write(2,'(e11.4,$)')(sin(y/degree)/cos(x/degree))
                end if 
                x = x+x_step
                if (x.gt.x_max) x=x_max
            end do
            write(2,'(/,$)')
            do k=1,(n+1)
                write(2,'(a,$)')'-------------'
            end do
            write(2,'(/,$)')
            y=y+y_step
            if (y.gt.y_max) y=y_max
        end do
  
        end
        
        
